/*
Daily Temperatures

You are given an array of integers temperatures where temperatures[i] represents
the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day
before a warmer temperature appears on a future day. If there is no day in the
future where a warmer temperature will appear for the ith day, set result[i] to 0.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            for(int j = i+1; j < temperatures.size(); j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(temps1);
    cout << "Example 1: [";
    for(int i = 0; i < res1.size(); i++)
        cout << res1[i] << (i + 1 < res1.size() ? "," : "");
    cout << "]" << endl;

    vector<int> temps2 = {30, 40, 50, 60};
    vector<int> res2 = sol.dailyTemperatures(temps2);
    cout << "Example 2: [";
    for(int i = 0; i < res2.size(); i++)
        cout << res2[i] << (i + 1 < res2.size() ? "," : "");
    cout << "]" << endl;

    return 0;
}
