/*
Copy List with Random Pointer

Create a deep copy of a linked list where each node has a next and random pointer.
Approach: weave copied nodes, assign randoms, then unweave.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x): val(x), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // weave
    Node* cur = head;
    while (cur) {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    // assign randoms
    cur = head;
    while (cur) {
        if (cur->random) cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    // unweave
    cur = head;
    Node* dummy = new Node(0);
    Node* copyTail = dummy;
    while (cur) {
        Node* copy = cur->next;
        cur->next = copy->next;
        copyTail->next = copy;
        copyTail = copy;
        cur = cur->next;
    }
    return dummy->next;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "Val:" << cur->val;
        if (cur->random) cout << " Rand:" << cur->random->val;
        cout << " | ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    n1->next = n2; n2->next = n3;
    n1->random = nullptr; n2->random = n1; n3->random = n1;
    cout << "Original: "; printList(n1);
    Node* cpy = copyRandomList(n1);
    cout << "Copied:   "; printList(cpy);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) extra (excluding output)
