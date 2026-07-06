#include <iostream>
#include <vector>
using namespace std;

// find all contiguous subarrays that sum to key
// example: arr = [1, 2, 3, 4, 5], key = 6
//          subarrays: [1,2,3] and [2,4] → wait, non-contiguous
//          contiguous: [1,2,3] (sum=6) and [2,4]? no
//          correct:    [1,2,3] sum=6, [2,4] not contiguous
//          result:     [[1,2,3]]

vector<vector<int>> func(vector<int>& arr, int key)
{
    int l = arr.size();
    vector<vector<int>> result;

    for (int i = 0; i < l; i++)
    {
        int sum = arr[i];
        vector<int> elements = {arr[i]};  // start subarray at i

        for (int j = i + 1; j < l; j++)
        {
            sum += arr[j];
            elements.push_back(arr[j]);

            if (sum == key)
            {
                result.push_back(elements);
                break;
            }
        }
    }
    return result;
}

int main()
{
    // example 1: [1,2,3,4,5], key=6
    // contiguous subarrays summing to 6: [1,2,3] and [2,4]?
    // [1,2,3]=6 ✓, [2,4] not contiguous, [6] no 6 in array
    // only: [1,2,3]
    vector<int> arr1 = {1, 2, 3, 4, 5};
    auto res1 = func(arr1, 6);
    cout << "arr=[1,2,3,4,5], key=6:\n";
    for (auto& sub : res1) {
        cout << "  [";
        for (int i = 0; i < sub.size(); i++)
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        cout << "]\n";
    }

    // example 2: [1,2,3,7,5], key=12
    // [2,3,7]=12 ✓, [7,5]=12 ✓
    vector<int> arr2 = {1, 2, 3, 7, 5};
    auto res2 = func(arr2, 12);
    cout << "arr=[1,2,3,7,5], key=12:\n";
    for (auto& sub : res2) {
        cout << "  [";
        for (int i = 0; i < sub.size(); i++)
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        cout << "]\n";
    }

    return 0;
}
