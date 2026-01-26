/*
Invert Binary Tree

Invert a binary tree by swapping left and right children for all nodes.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

void printPre(TreeNode* r) { if (!r) return; cout << r->val << ' '; printPre(r->left); printPre(r->right); }

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2); root->right = new TreeNode(7);
    root->left->left = new TreeNode(1); root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6); root->right->right = new TreeNode(9);
    invertTree(root);
    cout << "Inverted preorder: "; printPre(root); cout << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
