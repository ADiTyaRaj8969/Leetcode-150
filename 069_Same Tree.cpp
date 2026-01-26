/*
Same Tree

Check if two binary trees are structurally identical and nodes have the same value.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p = new TreeNode(1); p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1); q->left = new TreeNode(2);
    cout << "Same 1: " << (isSameTree(p,q) ? "true" : "false") << endl; // true

    q->left = nullptr; q->right = new TreeNode(2);
    cout << "Same 2: " << (isSameTree(p,q) ? "true" : "false") << endl; // false
    return 0;
}

// Time Complexity: O(min(n,m))
// Space Complexity: O(h)
