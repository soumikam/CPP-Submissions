/* 
Top K Frequent Elements Medium

Given an integer array nums and an integer k, 
return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]
Example 2:

Input: nums = [7,7], k = 1

Output: [7]
Constraints:

1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums. 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step 1 — build frequency hashtable
        unordered_map<int, int> freq;
        for (int x : nums) 
        {
            freq[x]++;
        }
        
        // step 2 — move map into vector of pairs to sort
        vector<pair<int,int>> sorted_freq(freq.begin(), freq.end());

        // step 3 — sort by frequency descending
        sort(sorted_freq.begin(), sorted_freq.end(), [](auto& a, auto& b) {
            return a.second > b.second;  // compare frequencies
        });

        // step 4 — take first k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(sorted_freq[i].first);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Example 1: [1,2,2,3,3,3], k=2 => [2,3]
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    vector<int> res1 = sol.topKFrequent(nums1, 2);
    cout << "Example 1: [";
    for (int i = 0; i < res1.size(); i++)
        cout << res1[i] << (i + 1 < res1.size() ? "," : "");
    cout << "]" << endl;

    // Example 2: [7,7], k=1 => [7]
    vector<int> nums2 = {7, 7};
    vector<int> res2 = sol.topKFrequent(nums2, 1);
    cout << "Example 2: [";
    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << (i + 1 < res2.size() ? "," : "");
    cout << "]" << endl;

    return 0;
}