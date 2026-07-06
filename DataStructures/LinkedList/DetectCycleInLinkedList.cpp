#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr){}
};

bool detectCycle(ListNode* head)
{   
    //Floyd's tortoise and hare
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            cout << "Cycle found" << endl;
            return true;
        }
    }
    return false;
}
ListNode* build(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) { tail->next = new ListNode(v); tail = tail->next; }
    return dummy.next;
}

void print(ListNode* head) {
    for (ListNode* n = head; n; n = n->next)
        cout << n->val << (n->next ? " -> " : "\n");
}
int main()
{
    // Test 1: no cycle
    ListNode* list = build({1, 2, 3, 6, 7, 2});
    cout << "Linear list: ";
    print(list);
    detectCycle(list);

    // Test 2: create a cycle  1->2->3->4->5->back to node 2
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n5->next = n2; // cycle: tail points back to n2
    cout << "Cyclic list (tail->n2): ";
    detectCycle(n1);

    return 0;
}