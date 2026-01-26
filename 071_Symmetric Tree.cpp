// Symmetric Tree
// Check whether a binary tree is a mirror of itself (symmetric around its center).
// Solution: recursively compare left and right subtrees for mirror property.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// small helper to build a tree for tests
TreeNode* buildExample1() { // symmetric
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(2);
    r->left->left = new TreeNode(3);
    r->left->right = new TreeNode(4);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(3);
    return r;
}

TreeNode* buildExample2() { // not symmetric
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(2);
    r->left->right = new TreeNode(3);
    r->right->right = new TreeNode(3);
    return r;
}

int main() {
    TreeNode* a = buildExample1();
    TreeNode* b = buildExample2();
    cout << boolalpha;
    cout << "Example1 is symmetric: " << isSymmetric(a) << "\n"; // true
    cout << "Example2 is symmetric: " << isSymmetric(b) << "\n"; // false
    cout << "Empty tree symmetric: " << isSymmetric(nullptr) << "\n"; // true
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) recursion stack where h is tree height
