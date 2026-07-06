/* 
Is Subsequence

Given two strings s and t, 
return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from 
the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters.
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).


Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false 
*/

#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i=0;
    int j=0;

    while(i < s.size() && j < t.size())
    {
        if(s[i]==t[j])
        {
            i++;
        }
        j++;
    }
    if(i == s.size())
    {
        return true;
    }
    else return false;
}

int main()
{
    string s, t;
    cout << "Enter s: ";
    cin >> s;
    cout << "Enter t: ";
    cin >> t;

    if(isSubsequence(s, t))
        cout << s << " is a subsequence of " << t << endl;
    else
        cout << s << " is NOT a subsequence of " << t << endl;

    return 0;
}