/*
Reverse Nodes in k-Group

Reverse nodes of a linked list k at a time and return the modified list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0); dummy.next = head;
    ListNode* groupPrev = &dummy;
    while (true) {
        ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth; ++i) kth = kth->next;
        if (!kth) break;
        ListNode* groupNext = kth->next;
        // reverse group
        ListNode* prev = groupNext;
        ListNode* cur = groupPrev->next;
        while (cur != groupNext) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        ListNode* tmp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = tmp;
    }
    return dummy.next;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(3); a->next->next->next = new ListNode(4); a->next->next->next->next = new ListNode(5);
    auto r = reverseKGroup(a, 2); // expected 2 1 4 3 5
    cout << "KGroup 1: "; printList(r);

    ListNode* b = new ListNode(1); b->next = new ListNode(2); b->next->next = new ListNode(3);
    cout << "KGroup 2: "; printList(reverseKGroup(b, 3)); // 3 2 1
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
