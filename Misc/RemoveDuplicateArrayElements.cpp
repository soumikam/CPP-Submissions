#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// return the sorted array without duplicates

vector<int> removeDuplicates(vector<int>& arr)
{
    if(arr.empty())
    {
        return {};
    }
    vector<int> result;
    result.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] != arr[i-1])
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

// return freq of each element in the array
unordered_map<int, int> frequencyTable(vector<int>& arr)
{
    unordered_map<int, int> freq;
    for(int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    return freq;
}


int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 5, 5, 6, 7, 7};
    vector<int> uniqueArr = removeDuplicates(arr);
    for(int i = 0; i < uniqueArr.size(); i++)
    {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;

    for(auto& [key, value] : frequencyTable(arr))
    {
        cout << key << ": " << value << endl;
    }
    
    return 0;
}