#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty()) return false;

            char top = st.top(); st.pop();

            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }

    return st.empty();
}

int main()
{
    cout << isValid("[]")       << "\n";  // 1
    cout << isValid("[{()}]")   << "\n";  // 1
    cout << isValid("(())")     << "\n";  // 1
    cout << isValid("()[]{}")   << "\n";  // 1
    cout << isValid("(]")       << "\n";  // 0
    cout << isValid("([)]")     << "\n";  // 0
    cout << isValid("(")        << "\n";  // 0
    return 0;
}
