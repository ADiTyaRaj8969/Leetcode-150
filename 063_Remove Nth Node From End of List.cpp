/*
Remove Nth Node From End of List

Remove the n-th node from the end of a linked list and return its head.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); dummy.next = head;
    ListNode* first = &dummy; ListNode* second = &dummy;
    for (int i = 0; i <= n; ++i) first = first->next;
    while (first) { first = first->next; second = second->next; }
    // second->next is the node to remove
    ListNode* toDel = second->next;
    second->next = toDel->next;
    delete toDel;
    return dummy.next;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(3); a->next->next->next = new ListNode(4); a->next->next->next->next = new ListNode(5);
    auto r = removeNthFromEnd(a, 2); // remove 4 -> expected 1 2 3 5
    cout << "RemoveNth 1: "; printList(r);

    ListNode* b = new ListNode(1);
    cout << "RemoveNth 2: "; printList(removeNthFromEnd(b,1)); // empty
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
