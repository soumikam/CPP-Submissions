#include <iostream>
using namespace std;

// ─────────────────────────────────────────
// NODE
// ─────────────────────────────────────────
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// ─────────────────────────────────────────
// PRINT
// ─────────────────────────────────────────
void print(Node* head) {
    while (head) { cout << head->val << " -> "; head = head->next; }
    cout << "NULL\n";
}

// ─────────────────────────────────────────
// INSERT
// ─────────────────────────────────────────
void insertFront(Node*& head, int val) {
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void insertEnd(Node*& head, int val) {
    Node* node = new Node(val);
    if (!head) { head = node; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

void insertAfter(Node* prev, int val) {
    if (!prev) return;
    Node* node = new Node(val);
    node->next = prev->next;
    prev->next = node;
}

// ─────────────────────────────────────────
// DELETE
// ─────────────────────────────────────────
void deleteFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteVal(Node*& head, int val) {
    if (!head) return;
    if (head->val == val) { deleteFront(head); return; }
    Node* cur = head;
    while (cur->next && cur->next->val != val) cur = cur->next;
    if (!cur->next) return;
    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

// ─────────────────────────────────────────
// SEARCH
// ─────────────────────────────────────────
Node* search(Node* head, int val) {
    while (head) {
        if (head->val == val) return head;
        head = head->next;
    }
    return nullptr;
}

// ─────────────────────────────────────────
// LENGTH
// ─────────────────────────────────────────
int length(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

// ─────────────────────────────────────────
// REVERSE
// ─────────────────────────────────────────
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* cur  = head;
    while (cur) {
        Node* next = cur->next;
        cur->next  = prev;
        prev       = cur;
        cur        = next;
    }
    return prev;
}

// ─────────────────────────────────────────
// DETECT CYCLE  (Floyd's algorithm)
// ─────────────────────────────────────────
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// ─────────────────────────────────────────
// FIND MIDDLE  (slow/fast pointers)
// ─────────────────────────────────────────
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ─────────────────────────────────────────
// NTH FROM END
// ─────────────────────────────────────────
Node* nthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < n; i++) {
        if (!fast) return nullptr;
        fast = fast->next;
    }
    while (fast) { slow = slow->next; fast = fast->next; }
    return slow;
}

// ─────────────────────────────────────────
// MERGE TWO SORTED LISTS
// ─────────────────────────────────────────
Node* mergeSorted(Node* l1, Node* l2) {
    Node dummy(0);
    Node* cur = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
        else                    { cur->next = l2; l2 = l2->next; }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

// ─────────────────────────────────────────
// REMOVE DUPLICATES (sorted list)
// ─────────────────────────────────────────
void removeDuplicates(Node* head) {
    while (head && head->next) {
        if (head->val == head->next->val) {
            Node* temp = head->next;
            head->next = temp->next;
            delete temp;
        } else {
            head = head->next;
        }
    }
}

// ─────────────────────────────────────────
// MAIN — demo
// ─────────────────────────────────────────
int main()
{
    Node* head = nullptr;

    // insert
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    cout << "List:       "; print(head);               // 1 2 3 4 5

    // insertFront
    insertFront(head, 0);
    cout << "Front ins:  "; print(head);               // 0 1 2 3 4 5

    // delete
    deleteVal(head, 3);
    cout << "Del 3:      "; print(head);               // 0 1 2 4 5

    // reverse
    head = reverse(head);
    cout << "Reversed:   "; print(head);               // 5 4 2 1 0

    // middle
    cout << "Middle:     " << findMiddle(head)->val << "\n";  // 2

    // nth from end
    cout << "2nd from end: " << nthFromEnd(head, 2)->val << "\n"; // 1

    // length
    cout << "Length:     " << length(head) << "\n";   // 5

    // cycle detection
    cout << "Has cycle:  " << hasCycle(head) << "\n"; // 0

    // merge sorted
    Node* a = nullptr; insertEnd(a,1); insertEnd(a,3); insertEnd(a,5);
    Node* b = nullptr; insertEnd(b,2); insertEnd(b,4); insertEnd(b,6);
    Node* merged = mergeSorted(a, b);
    cout << "Merged:     "; print(merged);             // 1 2 3 4 5 6

    return 0;
}
