"""
sort_cpp_files.py

Sorts files in a CPP-Submissions folder into topic-based subfolders
based on filename keyword matching.

Usage:
    1. Place this script inside (or point it at) your CPP-Submissions folder.
    2. Run:  python sort_cpp_files.py
    3. Review the "Misc" folder afterward for anything that needs manual sorting.

Notes:
    - .exe files are skipped by default (they shouldn't be committed to git anyway).
    - Matching is case-insensitive and based on keywords found in the filename.
    - Safe to re-run: already-sorted files (already inside a category folder)
      won't be touched, since the script only scans the top-level folder.
"""

import os
import shutil
from pathlib import Path

# ---- CONFIG ---------------------------------------------------------------

# Set this to your CPP-Submissions folder path.
# If you run the script from inside that folder, "." works fine.
TARGET_FOLDER = "."

# Skip these extensions entirely (won't be moved or counted)
SKIP_EXTENSIONS = {".exe", ".obj", ".o", ".pdb", ".ilk"}

# Category -> list of keywords (case-insensitive substring match on filename)
CATEGORIES = {
    "DataStructures/LinkedList":      ["linkedlist", "linked_list", "linked-list"],
    "DataStructures/Stacks-Queues":   ["stack", "queue"],
    "DataStructures/Trees":           ["tree", "bst", "trie", "heap"],
    "DataStructures/Graphs":          ["graph", "dijkstra", "bfs", "dfs", "unionfind", "union_find"],

    "Algorithms/Sorting":             ["sort"],
    "Algorithms/BinarySearch":        ["binarysearch", "binary_search"],
    "Algorithms/DynamicProgramming":  ["dp", "dynamicprogramming", "knapsack", "fibonacci"],
    "Algorithms/Recursion":           ["recursion", "recursive", "backtrack"],

    "LeetCode-Problems":              [
        "anagram", "subsequence", "buyandsell", "buyandsellstock",
        "dailytemperature", "twosum", "threesum", "cycle",
    ],

    "DesignPatterns":                 ["solid", "designpattern", "singleton", "factory", "observer"],

    "Concepts-Notes":                 [],  # handled separately: all .txt files go here
}

TXT_CATEGORY = "Concepts-Notes"
MISC_CATEGORY = "Misc"

# ---- SCRIPT -----------------------------------------------------------------

def categorize(filename: str) -> str:
    """Return the target category folder for a given filename."""
    name_lower = filename.lower()
    ext = Path(filename).suffix.lower()

    # All .txt notes go straight to Concepts-Notes
    if ext == ".txt":
        return TXT_CATEGORY

    for category, keywords in CATEGORIES.items():
        for kw in keywords:
            if kw in name_lower:
                return category

    return MISC_CATEGORY


def sort_files(target_folder: str):
    target = Path(target_folder).resolve()
    moved = []
    skipped = []

    for entry in target.iterdir():
        if entry.is_dir():
            continue  # don't touch existing folders (or the script itself)
        if entry.name == Path(__file__).name:
            continue  # don't move this script
        if entry.suffix.lower() in SKIP_EXTENSIONS:
            skipped.append(entry.name)
            continue

        category = categorize(entry.name)
        dest_folder = target / category
        dest_folder.mkdir(parents=True, exist_ok=True)

        dest_path = dest_folder / entry.name
        shutil.move(str(entry), str(dest_path))
        moved.append((entry.name, category))

    # ---- Report ----
    print(f"\nSorted {len(moved)} file(s):\n")
    for name, category in moved:
        print(f"  {name:<45} -> {category}/")

    if skipped:
        print(f"\nSkipped {len(skipped)} file(s) (excluded extensions): {', '.join(skipped)}")

    misc_count = sum(1 for _, c in moved if c == MISC_CATEGORY)
    if misc_count:
        print(f"\n{misc_count} file(s) went to '{MISC_CATEGORY}/' — review these manually "
              f"and either rename+re-run, or move them by hand into the right category.")

    print("\nDone.")


if __name__ == "__main__":
    sort_files(TARGET_FOLDER)
