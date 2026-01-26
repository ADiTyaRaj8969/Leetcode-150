"""
Construct Binary Tree from Inorder and Postorder Traversal
Build a binary tree given inorder and postorder traversal arrays.
"""
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        idx = {v:i for i,v in enumerate(inorder)}
        self.postIndex = len(postorder)-1

        def build(l, r):
            if l>r: return None
            rootVal = postorder[self.postIndex]; self.postIndex -= 1
            root = TreeNode(rootVal)
            mid = idx[rootVal]
            root.right = build(mid+1, r)
            root.left = build(l, mid-1)
            return root

        return build(0, len(inorder)-1)

def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

if __name__ == '__main__':
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    root = Solution().buildTree(inorder, postorder)
    print('Inorder of built tree:', inorder_traversal(root))

# Time Complexity: O(n)
# Space Complexity: O(n)
