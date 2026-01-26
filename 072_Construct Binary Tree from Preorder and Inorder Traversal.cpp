// Construct Binary Tree from Preorder and Inorder Traversal
// Build a binary tree given its preorder and inorder traversal arrays.
// Solution: use hashmap for inorder indices and recursive builder from preorder index.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

class Solution {
    unordered_map<int,int> idx;
    vector<int> pre;
    int preIndex = 0;
public:
    TreeNode* build(int l, int r) {
        if (l>r) return nullptr;
        int rootVal = pre[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];
        root->left = build(l, mid-1);
        root->right = build(mid+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        preIndex = 0;
        idx.clear();
        for (int i=0;i<inorder.size();++i) idx[inorder[i]] = i;
        return build(0, (int)inorder.size()-1);
    }
};

// simple in-order traversal to verify
void printInorder(TreeNode* r) {
    if (!r) return;
    printInorder(r->left);
    cout<<r->val<<" ";
    printInorder(r->right);
}

int main(){
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout<<"Inorder of built tree: "; printInorder(root); cout<<"\n"; // should match inorder
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
