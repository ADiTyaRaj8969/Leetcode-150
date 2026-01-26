"""
Construct Binary Tree from Preorder and Inorder Traversal
Build a binary tree given preorder and inorder traversal arrays.
"""
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        idx = {v:i for i,v in enumerate(inorder)}
        self.preIndex = 0

        def build(l, r):
            if l>r: return None
            rootVal = preorder[self.preIndex]; self.preIndex += 1
            root = TreeNode(rootVal)
            mid = idx[rootVal]
            root.left = build(l, mid-1)
            root.right = build(mid+1, r)
            return root

        return build(0, len(inorder)-1)

def inorder_traversal(root):
    return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right) if root else []

if __name__ == '__main__':
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    root = Solution().buildTree(preorder, inorder)
    print('Inorder of built tree:', inorder_traversal(root))

# Time Complexity: O(n)
# Space Complexity: O(n)
