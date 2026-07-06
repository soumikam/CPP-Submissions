#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr){}
};

ListNode* findMidElement(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    //detect cycle
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){break;}
    }

    //no cycle
    if (!fast || !fast->next) return nullptr;

    // step 2 — find entry point
    // move one pointer to head, keep other at meeting point
    // both move 1 step — they meet at cycle start
    slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next; // one step each — they meet at cycle start
    }

    return slow;
}

int main()
{
    // Build: 1->2->3->4->5->back to node 3 (cycle start)
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n5->next = n3; // cycle: tail points back to n3

    ListNode* cycleStart = findMidElement(n1);
    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle found" << endl;

    return 0;
}