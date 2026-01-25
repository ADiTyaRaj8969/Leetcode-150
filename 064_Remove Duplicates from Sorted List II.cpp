/*
Remove Duplicates from Sorted List II

Delete all nodes that have duplicate numbers from a sorted linked list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0); dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next) {
        ListNode* curr = prev->next;
        bool dup = false;
        while (curr->next && curr->val == curr->next->val) {
            dup = true;
            ListNode* tmp = curr->next; curr->next = tmp->next; delete tmp;
        }
        if (dup) { // remove curr as well
            ListNode* tmp = curr;
            prev->next = curr->next;
            delete tmp;
        } else prev = prev->next;
    }
    return dummy.next;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << ' '; h = h->next; } cout << endl; }

int main() {
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(3); a->next->next->next = new ListNode(3); a->next->next->next->next = new ListNode(4);
    auto r = deleteDuplicates(a); // expected 1 2 4
    cout << "DelDup 1: "; printList(r);

    ListNode* b = new ListNode(1); b->next = new ListNode(1); b->next->next = new ListNode(1); b->next->next->next = new ListNode(2); b->next->next->next->next = new ListNode(3);
    cout << "DelDup 2: "; printList(deleteDuplicates(b)); // 2 3
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
