/*
Reverse Linked List II

Reverse the nodes of a linked list from position left to right (1-indexed).
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    ListNode dummy(0); dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 1; i < left; ++i) prev = prev->next;
    ListNode* cur = prev->next;
    for (int i = 0; i < right - left; ++i) {
        ListNode* tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return dummy.next;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2); a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4); a->next->next->next->next = new ListNode(5);
    auto r = reverseBetween(a, 2, 4); // expected 1 4 3 2 5
    cout << "RevII 1: "; printList(r);

    ListNode* b = new ListNode(5);
    cout << "RevII 2: "; printList(reverseBetween(b,1,1));
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
