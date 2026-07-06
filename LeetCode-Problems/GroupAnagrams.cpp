/*
Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

Example 1:
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> map;

        for(string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); // "eat" -> "aet"
            map[key].push_back(s);        // group by sorted key
        }

        vector<vector<string>> result;
        for(auto& [key, group] : map)
            result.push_back(group);

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);

    for(auto& group : res)
    {
        cout << "[";
        for(int i = 0; i < group.size(); i++)
            cout << group[i] << (i + 1 < group.size() ? "," : "");
        cout << "]" << endl;
    }

    return 0;
}
