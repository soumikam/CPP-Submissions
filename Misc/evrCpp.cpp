#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Forward declaration so main() can call factorial() defined below
long long factorial(int num);

int main(){
    int number;
    cout << "Enter a number";
    cin >> number;

    long long fact = 0L;
    fact = factorial(number); // compute factorial; returns -1 for negative input

    // Negative numbers have no factorial
    if(number < 0)
    {
        cout << "Factorial of " << number << " is NOT POSSIBLE";
    }
    // Base case: 0! = 1! = 1
    if(number == 0 || number == 1)
    {
        cout << "Factorial of " << number << " is 1";
    }
    // General case: display the computed result
    if(number > 1)
    {
        cout << "Factorial of " << number << " is " << fact;
    }

    return 0;
}

// Recursively computes num! (num factorial).
// Returns -1 if num is negative (invalid input).
long long factorial(int num){
    if(num<0) return -1;          // guard: factorial undefined for negatives
    if(num==0 || num==1) return 1; // base case
    return num * factorial(num-1); // recursive step: n! = n * (n-1)!
}
