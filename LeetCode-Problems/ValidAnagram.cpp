/* 
Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other,
otherwise return false.

An anagram is a string that contains the exact same characters as another string,
 but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true 
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length()) // different length, not ANAGRAM
        {
            return false;
        }
        
        unordered_map<char, int> frequency;
        for(int i=0; i<s.length(); i++)
        {
            //logic tends all character frequency to be 0
            frequency[s[i]]++;
            frequency[t[i]]--;
        }

        /* Without the &:
        for(auto [key, val] : frequency)  // copies every pair — wasteful
        
        With &:
        for(auto& [key, val] : frequency) // references the pair in-place — efficient */
        
        for(auto&[key,val]:frequency)
        {
            if(val!=0) 
            { 
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s1;
    string s2;
    bool val = false;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << endl;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << endl;

    Solution sol;
    val = sol.isAnagram(s1, s2);

    if(val)
    {
        cout << "ANAGRAM";
    }
    else{
        cout << "NOT ANAGRAM";
    }
    return 0;
}