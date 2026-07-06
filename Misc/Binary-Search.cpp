#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main()
{
    cout << "Enter number of elements: ";
    int n; cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    int target; cin >> target;

    Solution sol;
    int result = sol.search(nums, target);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found, returning -1" << endl;

    return 0;
}
