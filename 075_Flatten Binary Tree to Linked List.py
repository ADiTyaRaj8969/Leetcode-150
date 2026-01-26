"""
Flatten Binary Tree to Linked List
Flatten the tree to a linked list in-place following preorder traversal.
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.prev = None
    def flatten(self, root: Optional[TreeNode]) -> None:
        if not root: return
        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.prev
        root.left = None
        self.prev = root

def print_list(root):
    res = []
    while root:
        res.append(root.val)
        root = root.right
    print(res)

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)
    Solution().flatten(root)
    print_list(root)  # [1,2,3,4,5,6]

# Time Complexity: O(n)
# Space Complexity: O(h)
