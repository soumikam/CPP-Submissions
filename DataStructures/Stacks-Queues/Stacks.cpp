#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// ── 1. STACK BASICS ───────────────────────────────────────────────────────────
// LIFO — Last In First Out
// push() adds to top, pop() removes from top
void stackBasics()
{
    cout << "── Stack Basics ──" << endl;
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top:   " << s.top()   << endl;  // 30
    cout << "Size:  " << s.size()  << endl;  // 3
    cout << "Empty: " << s.empty() << endl;  // 0 (false)

    s.pop();  // removes 30
    cout << "After pop, Top: " << s.top() << endl;  // 20

    cout << "Traverse (top to bottom): ";
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << endl;
}

// ── 2. STACK USING ARRAY ──────────────────────────────────────────────────────
// Manual implementation without STL
class StackArray
{
    vector<int> arr;
    int top_;

public:
    StackArray() : top_(-1) {}

    void push(int val)
    {
        arr.push_back(val);
        top_++;
    }

    void pop()
    {
        if(empty()) return;
        arr.pop_back();
        top_--;
    }

    int top()    { return arr[top_]; }
    bool empty() { return top_ == -1; }
    int size()   { return top_ + 1; }
};

void stackArrayDemo()
{
    cout << "── Stack Using Array ──" << endl;
    StackArray s;
    s.push(1); s.push(2); s.push(3);
    cout << "Top: " << s.top() << endl;  // 3
    s.pop();
    cout << "After pop, Top: " << s.top() << endl;  // 2
    cout << endl;
}

// ── 3. STACK USING LINKED LIST ────────────────────────────────────────────────
struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class StackLinkedList
{
    Node* top_;

public:
    StackLinkedList() : top_(nullptr) {}

    void push(int val)
    {
        Node* node = new Node(val);
        node->next = top_;
        top_ = node;
    }

    void pop()
    {
        if(!top_) return;
        Node* tmp = top_;
        top_ = top_->next;
        delete tmp;
    }

    int top()    { return top_->val; }
    bool empty() { return top_ == nullptr; }
};

void stackLinkedListDemo()
{
    cout << "── Stack Using Linked List ──" << endl;
    StackLinkedList s;
    s.push(1); s.push(2); s.push(3);
    cout << "Top: " << s.top() << endl;  // 3
    s.pop();
    cout << "After pop, Top: " << s.top() << endl;  // 2
    cout << endl;
}

// ── 4. VALID PARENTHESES ──────────────────────────────────────────────────────
// Classic stack problem — check if brackets are balanced
bool isValid(string s)
{
    stack<char> st;
    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else
        {
            if(st.empty()) return false;
            char top = st.top(); st.pop();
            if(c == ')' && top != '(') return false;
            if(c == '}' && top != '{') return false;
            if(c == ']' && top != '[') return false;
        }
    }
    return st.empty();
}

void validParenthesesDemo()
{
    cout << "── Valid Parentheses ──" << endl;
    cout << "\"()[]{}\"  : " << (isValid("()[]{}") ? "Valid" : "Invalid") << endl;   // Valid
    cout << "\"(]\"      : " << (isValid("(]")     ? "Valid" : "Invalid") << endl;   // Invalid
    cout << "\"{[()]}\"  : " << (isValid("{[()]}") ? "Valid" : "Invalid") << endl;   // Valid
    cout << endl;
}

// ── 5. REVERSE A STRING USING STACK ──────────────────────────────────────────
string reverseString(string s)
{
    stack<char> st;
    for(char c : s) st.push(c);
    string result = "";
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

void reverseStringDemo()
{
    cout << "── Reverse String Using Stack ──" << endl;
    cout << "\"hello\" -> \"" << reverseString("hello") << "\"" << endl;
    cout << endl;
}

// ── 6. MIN STACK ──────────────────────────────────────────────────────────────
// Stack that retrieves minimum element in O(1)
class MinStack
{
    stack<int> s;
    stack<int> minS;  // tracks minimums

public:
    void push(int val)
    {
        s.push(val);
        if(minS.empty() || val <= minS.top())
            minS.push(val);
    }

    void pop()
    {
        if(s.top() == minS.top())
            minS.pop();
        s.pop();
    }

    int top()    { return s.top(); }
    int getMin() { return minS.top(); }
};

void minStackDemo()
{
    cout << "── Min Stack ──" << endl;
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);
    cout << "Top: "    << ms.top()    << endl;  // 2
    cout << "Min: "    << ms.getMin() << endl;  // 2
    ms.pop();
    cout << "After pop, Min: " << ms.getMin() << endl;  // 3
    cout << endl;
}

// ── 7. NEXT GREATER ELEMENT ───────────────────────────────────────────────────
// For each element, find the next greater element to its right
// Uses monotonic stack — O(n)
vector<int> nextGreaterElement(vector<int>& nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // stores indices

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && nums[i] > nums[st.top()])
        {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

void nextGreaterDemo()
{
    cout << "── Next Greater Element ──" << endl;
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> res = nextGreaterElement(nums);
    cout << "Input:  [4,5,2,10,8]" << endl;
    cout << "Output: [";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? "," : "");
    cout << "]" << endl;  // [5,10,10,-1,-1]
    cout << endl;
}

int main()
{
    stackBasics();
    stackArrayDemo();
    stackLinkedListDemo();
    validParenthesesDemo();
    reverseStringDemo();
    minStackDemo();
    nextGreaterDemo();
    return 0;
}
