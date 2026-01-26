/*
Rotate List

Rotate a linked list to the right by k places.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int n = 1;
    ListNode* tail = head;
    while (tail->next) { tail = tail->next; ++n; }
    k %= n;
    if (k == 0) return head;
    // make circular
    tail->next = head;
    int steps = n - k;
    ListNode* newTail = tail;
    for (int i = 0; i < steps; ++i) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(3); a->next->next->next = new ListNode(4); a->next->next->next->next = new ListNode(5);
    auto r = rotateRight(a, 2); // expected 4 5 1 2 3
    cout << "RotateList 1: "; printList(r);

    ListNode* b = new ListNode(0); b->next = new ListNode(1);
    cout << "RotateList 2: "; printList(rotateRight(b, 4)); // 1 0
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
