#include <iostream>
using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n * fact(n-1);

}

int main()
{
    int factorial = 0;
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << endl;
    if(num < 0)
    {
        cout << "Not POSSIBLE -VE Number" << endl;
        return 1;
    }
    factorial = fact(num);
    cout << "Factorial is " << factorial << endl;
}