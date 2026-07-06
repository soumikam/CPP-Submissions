#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr){}
};

int main()
{
    // create nodes
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    // 1->2->3

    //traverse
    ListNode* curr = head;
    while(curr != nullptr)
    {   
        cout << curr->val << " ";
        curr = curr->next;
    }

    //insert at front
    ListNode* newNode = new ListNode(0);
    newNode->next = head;
    head=newNode;

    //insert at end
    ListNode* newEndNode = new ListNode(4);
    

}
