#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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

int main() {
    ListNode* list = build({1, 2, 3, 4, 5});
    cout << "Original: ";
    print(list);
    list = reverseList(list);
    cout << "Reversed: ";
    print(list);
    return 0;
}
