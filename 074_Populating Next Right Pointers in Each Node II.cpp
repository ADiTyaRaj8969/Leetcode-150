// Populating Next Right Pointers in Each Node II
// Populate each node's next pointer to its next right node in a binary tree (O(1) extra space).
#include <bits/stdc++.h>
using namespace std;

struct Node {int val; Node* left; Node* right; Node* next; Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {}};

class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root; // current level head
        while (head) {
            Node* dummy = new Node(0);
            Node* tail = dummy;
            for (Node* p = head; p; p = p->next) {
                if (p->left) { tail->next = p->left; tail = tail->next; }
                if (p->right) { tail->next = p->right; tail = tail->next; }
            }
            head = dummy->next;
            delete dummy;
        }
        return root;
    }
};

// small test build
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    Solution().connect(root);
    // print level order using next pointers
    Node* level = root;
    while (level) {
        Node* cur = level;
        while (cur) { cout<<cur->val<<" "; cur = cur->next; }
        cout<<"\n";
        // find next level head
        Node* nextHead = nullptr;
        for (Node* p=level; p; p=p->next) {
            if (p->left) { nextHead = p->left; break; }
            if (p->right) { nextHead = p->right; break; }
        }
        level = nextHead;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) extra space (excluding recursion/aux memory)
