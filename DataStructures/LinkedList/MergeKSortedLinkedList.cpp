#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr){}
};


ListNode* mergeKList(vector<ListNode*>& lists)
{
	vector<int> result;
	for(auto list : lists)
    {
	    for(ListNode* p = list; p; p=p->next)
        {	
	        result.push_back(p->val);
        }
    }

    sort(result.begin(), result.end());

    ListNode dummy(0);
    ListNode* curr = &dummy;

    for(int v : result)
    {
        curr->next = new ListNode(v);
        curr = curr->next;
    }

    return dummy.next;
}


int main()
{
    // List 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // List 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* result = mergeKList(lists);

    cout << "Merged: ";
    for (ListNode* p = result; p; p = p->next)
        cout << p->val << (p->next ? " -> " : "\n");

    return 0;
}