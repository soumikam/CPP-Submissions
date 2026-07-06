#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n < 0) return -1; // invalid
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = factorial(n);
    if (result == -1)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << "Factorial of " << n << " = " << result << endl;

    return 0;
}
