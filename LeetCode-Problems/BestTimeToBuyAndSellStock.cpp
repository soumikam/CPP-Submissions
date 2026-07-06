/*
Best Time to Buy and Sell Stock

You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
Return the maximum profit you can achieve. You may choose to not make any transactions,
in which case the profit would be 0.

Example 1:
Input: prices = [10,1,5,6,7,1]
Output: 6

Example 2:
Input: prices = [10,9,8,7,6,5]
Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int diff = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = i+1; j < prices.size(); j++)
            {
                diff = prices[j] - prices[i];
                if(diff > max)
                {
                    max = diff;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;

    vector<int> prices1 = {10, 1, 5, 6, 7, 1};
    cout << "Example 1: " << sol.maxProfit(prices1) << endl; // 6

    vector<int> prices2 = {10, 9, 8, 7, 6, 5};
    cout << "Example 2: " << sol.maxProfit(prices2) << endl; // 0

    return 0;
}
