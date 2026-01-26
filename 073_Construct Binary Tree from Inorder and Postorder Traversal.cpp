// Construct Binary Tree from Inorder and Postorder Traversal
// Build a binary tree given its inorder and postorder traversal arrays.
// Solution: use hashmap for inorder indices and recursive builder using postorder index from end.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {int val; TreeNode* left; TreeNode* right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {}};

class Solution {
    unordered_map<int,int> idx;
    vector<int> post;
    int postIndex;
public:
    TreeNode* build(int l, int r) {
        if (l>r) return nullptr;
        int rootVal = post[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];
        // build right first because postorder gives root after children
        root->right = build(mid+1, r);
        root->left = build(l, mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        postIndex = (int)post.size()-1;
        idx.clear();
        for (int i=0;i<inorder.size();++i) idx[inorder[i]] = i;
        return build(0, (int)inorder.size()-1);
    }
};

void printInorder(TreeNode* r) {
    if (!r) return;
    printInorder(r->left);
    cout<<r->val<<" ";
    printInorder(r->right);
}

int main(){
    Solution sol;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    cout<<"Inorder of built tree: "; printInorder(root); cout<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
