#include <iostream>

using namespace std;

int squareRoot(int num)
{
    if(num == 0) return 0;
    int left = 1, right = num, ans = 0;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(mid * mid <= num)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Square root of " << num << " = " << squareRoot(num) << endl;
    return 0;
}
