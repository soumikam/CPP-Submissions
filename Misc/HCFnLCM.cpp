#include <iostream>
#include <vector>
using namespace std;

// Euclidean algorithm — recursive
int hcf(int a, int b)
{
    return b == 0 ? a : hcf(b, a % b);
}

// LCM using the relation: a * b = HCF * LCM
long long lcm(int a, int b)
{
    return (long long)a / hcf(a, b) * b;  // divide first to avoid overflow
}

// HCF of an array
int hcfArray(vector<int>& arr)
{
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++)
        result = hcf(result, arr[i]);
    return result;
}

// LCM of an array
long long lcmArray(vector<int>& arr)
{
    long long result = arr[0];
    for (int i = 1; i < arr.size(); i++)
        result = lcm(result, arr[i]);
    return result;
}

int main()
{
    cout << "HCF(48, 18)   = " << hcf(48, 18)   << "\n";  // 6
    cout << "LCM(48, 18)   = " << lcm(48, 18)   << "\n";  // 144
    cout << "HCF(100, 75)  = " << hcf(100, 75)  << "\n";  // 25
    cout << "LCM(100, 75)  = " << lcm(100, 75)  << "\n";  // 300
    cout << "\n";

    vector<int> arr = {12, 18, 24};
    cout << "HCF(12,18,24) = " << hcfArray(arr) << "\n";  // 6
    cout << "LCM(12,18,24) = " << lcmArray(arr) << "\n";  // 72

    return 0;
}
