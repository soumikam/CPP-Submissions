/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result
*/

#include <iostream>
#include <climits>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int size = s.size();
    int sign = 1;
    long result = 0;

    while(i < size && s[i] == ' ')
    {
        i++;
    }

    if(i < size && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while(i < size && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');

        if(result * sign > INT_MAX) return INT_MAX;
        if(result * sign < INT_MIN) return INT_MIN;
        i++;
    }
    
    return (int)(result * sign);
}

int main()
{
    string customString;
    cout << "Enter string: ";
    cin >> customString;
    cout << endl;
    cout << "Converted integer acc. to rules is: " << myAtoi(customString);
}