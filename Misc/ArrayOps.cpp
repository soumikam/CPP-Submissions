#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

// ─────────────────────────────────────────
// EASY
// ─────────────────────────────────────────

// sum of all elements
int sumOfArray(vector<int>& arr) {
    int sum = 0;
    for (int x : arr) sum += x;
    return sum;
}

// max and min element
int maxElement(vector<int>& arr) 
{ 
    return *max_element(arr.begin(), arr.end()); 
}
int minElement(vector<int>& arr) 
{ 
    return *min_element(arr.begin(), arr.end()); 
}

// reverse an array in place
void reverseArray(vector<int>& arr) 
{
    int l = 0, r = arr.size() - 1;
    while (l < r) 
    {
        swap(arr[l++], arr[r--]);}
}

// check if array is sorted ascending
bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i-1]) return false;
    return true;
}

// remove duplicates from sorted array (in-place), return new length
// [1,1,2,3,3] → [1,2,3] returns 3
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    int k = 0;
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] != arr[k]) arr[++k] = arr[i];
    return k + 1;
}

// move all zeros to end, maintain order of non-zeros
// [0,1,0,3,12] → [1,3,12,0,0]
void moveZeros(vector<int>& arr) {
    int k = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != 0) arr[k++] = arr[i];
    while (k < arr.size()) arr[k++] = 0;
}

// two sum — return indices of two numbers that add to target
// arr = [2,7,11,15], target = 9 → [0,1]
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen;  // value → index
    for (int i = 0; i < arr.size(); i++) {
        int need = target - arr[i];
        if (seen.count(need)) return {seen[need], i};
        seen[arr[i]] = i;
    }
    return {};
}

// contains duplicate
// [1,2,3,1] → true
bool containsDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

// intersection of two arrays (unique elements)
// [1,2,2,1] & [2,2] → [2]
vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> setA(a.begin(), a.end());
    vector<int> result;
    for (int x : b)
        if (setA.count(x)) { result.push_back(x); setA.erase(x); }
    return result;
}

// single number — every element appears twice except one
// [4,1,2,1,2] → 4
int singleNumber(vector<int>& arr) {
    int res = 0;
    for (int x : arr) res ^= x;
    return res;
}

// plus one — increment number represented as digit array
// [1,2,9] → [1,3,0]
vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) { digits[i]++; return digits; }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

// ─────────────────────────────────────────
// MEDIUM
// ─────────────────────────────────────────

// maximum subarray sum (Kadane's algorithm)
// [-2,1,-3,4,-1,2,1,-5,4] → 6  (subarray [4,-1,2,1])
int maxSubarraySum(vector<int>& arr) {
    int maxSum = arr[0], cur = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        cur = max(arr[i], cur + arr[i]);
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

// maximum product subarray
// [2,3,-2,4] → 6  (subarray [2,3])
int maxProduct(vector<int>& arr) {
    int maxP = arr[0], minP = arr[0], result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < 0) swap(maxP, minP);
        maxP = max(arr[i], maxP * arr[i]);
        minP = min(arr[i], minP * arr[i]);
        result = max(result, maxP);
    }
    return result;
}

// prefix sum — answer range sum queries in O(1)
// arr = [1,2,3,4,5], query sum from index 1 to 3 → 2+3+4 = 9
vector<int> buildPrefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        prefix[i+1] = prefix[i] + arr[i];
    return prefix;
}
int rangeSum(vector<int>& prefix, int l, int r) {  // inclusive [l,r]
    return prefix[r+1] - prefix[l];
}

// best time to buy and sell stock (one transaction)
// [7,1,5,3,6,4] → 5  (buy at 1, sell at 6)
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice   = min(minPrice, p);
        maxProfit  = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}

// rotate array right by k steps
// [1,2,3,4,5], k=2 → [4,5,1,2,3]
void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    reverse(arr.begin(),     arr.end());
    reverse(arr.begin(),     arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

// sort array of 0s, 1s, 2s (Dutch National Flag)
// [2,0,2,1,1,0] → [0,0,1,1,2,2]
void sortColors(vector<int>& arr) {
    int lo = 0, mid = 0, hi = arr.size() - 1;
    while (mid <= hi) {
        if      (arr[mid] == 0) swap(arr[lo++], arr[mid++]);
        else if (arr[mid] == 1) mid++;
        else                    swap(arr[mid],  arr[hi--]);
    }
}

// find majority element (appears > n/2 times) — Boyer-Moore voting
// [3,2,3] → 3
int majorityElement(vector<int>& arr) {
    int candidate = arr[0], count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (count == 0) { candidate = arr[i]; count = 1; }
        else count += (arr[i] == candidate) ? 1 : -1;
    }
    return candidate;
}

// product of array except self (no division)
// [1,2,3,4] → [24,12,8,6]
vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; i++) { result[i] = prefix; prefix *= arr[i]; }
    int suffix = 1;
    for (int i = n-1; i >= 0; i--) { result[i] *= suffix; suffix *= arr[i]; }
    return result;
}

// ─────────────────────────────────────────
// MAIN — demo
// ─────────────────────────────────────────
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum:  " << maxSubarraySum(arr) << "\n";  // 6

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit:        " << maxProfit(prices) << "\n";    // 5

    vector<int> nums = {2, 7, 11, 15};
    auto ts = twoSum(nums, 9);
    cout << "Two sum [9]:       [" << ts[0] << "," << ts[1] << "]\n";  // [0,1]

    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    cout << "Sort 0s,1s,2s:     ";
    for (int x : colors) cout << x << " ";  // 0 0 1 1 2 2
    cout << "\n";

    vector<int> rot = {1, 2, 3, 4, 5};
    rotateArray(rot, 2);
    cout << "Rotated by 2:      ";
    for (int x : rot) cout << x << " ";     // 4 5 1 2 3
    cout << "\n";

    vector<int> p = {1, 2, 3, 4};
    auto prod = productExceptSelf(p);
    cout << "Product except self: ";
    for (int x : prod) cout << x << " ";   // 24 12 8 6
    cout << "\n";

    vector<int> pref = {1, 2, 3, 4, 5};
    auto prefix = buildPrefixSum(pref);
    cout << "Range sum [1,3]:   " << rangeSum(prefix, 1, 3) << "\n";  // 9

    return 0;
}
