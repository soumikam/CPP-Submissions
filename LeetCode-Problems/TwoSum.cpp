/* Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> arr(2);
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    arr = {i,j};
                    break;
                }
            }
        }
        return arr;    
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    cout << "Input: [2, 7, 11, 15], target = 9" << endl;
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    // Second test
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Input: [3, 2, 4], target = 6" << endl;
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}