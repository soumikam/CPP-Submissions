/* 
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros. 
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr){}
};

ListNode* addTwoLinkedList(ListNode* l1, ListNode* l2)
{
    ListNode dummy(0);
    ListNode* curr = &dummy;

    int carry = 0;

    while(carry || l1 || l2)
    {
        int sum = carry;

        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10;
        curr->next = new ListNode(sum%10);
        curr = curr->next;
    }
    return dummy.next;
}

int main()
{
    // Example 1: 342 + 465 = 807 => [7,0,8]
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* res = addTwoLinkedList(l1, l2);

    cout << "[";
    for (ListNode* p = res; p; p = p->next)
        cout << p->val << (p->next ? "," : "");
    cout << "]" << endl;

    return 0;
}