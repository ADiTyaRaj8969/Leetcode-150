/*
Linked List Cycle

Determine if a linked list has a cycle using Floyd's cycle detection.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // create list 3->2->0->-4 with cycle to node at index 1
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);
    a->next = b; b->next = c; c->next = d; d->next = b; // cycle
    cout << "Cycle 1: " << (hasCycle(a) ? "true" : "false") << endl; // true

    ListNode* x = new ListNode(1);
    ListNode* y = new ListNode(2);
    x->next = y; y->next = nullptr;
    cout << "Cycle 2: " << (hasCycle(x) ? "true" : "false") << endl; // false
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
