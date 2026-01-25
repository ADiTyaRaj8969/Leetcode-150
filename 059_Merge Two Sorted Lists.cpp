/*
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new sorted list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(ListNode* head) { while (head) { cout << head->val; if (head->next) cout << ' '; head = head->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(4);
    ListNode* b = new ListNode(1); b->next = new ListNode(3); b->next->next = new ListNode(4);
    auto r = mergeTwoLists(a,b);
    cout << "Merged: "; printList(r); // 1 1 2 3 4 4
    return 0;
}

// Time Complexity: O(m+n)
// Space Complexity: O(1)
