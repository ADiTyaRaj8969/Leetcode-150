/*
Partition List

Partition a linked list around value x, preserving relative order.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* partition(ListNode* head, int x) {
    ListNode before(0), after(0);
    ListNode* b = &before, *a = &after;
    while (head) {
        if (head->val < x) { b->next = head; b = b->next; }
        else { a->next = head; a = a->next; }
        head = head->next;
    }
    a->next = nullptr;
    b->next = after.next;
    return before.next;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(4); a->next->next = new ListNode(3); a->next->next->next = new ListNode(2); a->next->next->next->next = new ListNode(5); a->next->next->next->next->next = new ListNode(2);
    auto r = partition(a, 3); // expected 1 2 2 4 3 5
    cout << "Partition: "; printList(r);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
