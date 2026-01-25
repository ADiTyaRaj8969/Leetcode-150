/*
Add Two Numbers

Add two numbers represented by linked lists where digits are stored in reverse order.
Return the sum as a linked list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        cur->next = new ListNode(sum % 10);
        carry = sum / 10;
        cur = cur->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << ' '; head = head->next; }
    cout << endl;
}

int main() {
    // 342 + 465 = 807
    ListNode* a = new ListNode(2);
    a->next = new ListNode(4); a->next->next = new ListNode(3);
    ListNode* b = new ListNode(5);
    b->next = new ListNode(6); b->next->next = new ListNode(4);
    ListNode* r = addTwoNumbers(a,b);
    cout << "Add 1: "; printList(r); // 7 0 8

    // 0 + 0 = 0
    ListNode* x = new ListNode(0);
    ListNode* y = new ListNode(0);
    printList(addTwoNumbers(x,y)); // 0
    return 0;
}

// Time Complexity: O(max(m,n))
// Space Complexity: O(max(m,n)) for output
