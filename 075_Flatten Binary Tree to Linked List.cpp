// Flatten Binary Tree to Linked List
// Flatten the tree to a linked list in-place following preorder traversal.
// Solution: recursive reverse-preorder (right-left-root) and keep a prev pointer.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

class Solution {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

void printList(TreeNode* r) {
    while (r) { cout<<r->val<<" "; r = r->right; }
    cout<<"\n";
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution().flatten(root);
    printList(root); // expected 1 2 3 4 5 6
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) recursion stack
