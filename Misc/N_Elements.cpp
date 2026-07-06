#include <iostream>
#include <cmath>
using namespace std;

// Prints 1 to N using recursion
void recurPrint(int i, int N){
    if(i>N){
        return;
    }
    cout << i << " ";
    recurPrint(i+1, N);
}

int main(){
    int num;
    cout << "Enter the range: \n";
    cin >> num;
    cout << "Numbers from 1 to " << num << " are:\n";
    recurPrint(1,num);
}