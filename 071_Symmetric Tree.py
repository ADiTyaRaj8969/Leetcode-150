"""
Symmetric Tree
Check whether a binary tree is a mirror of itself (symmetric around its center).
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def is_mirror(a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
    if not a and not b:
        return True
    if not a or not b:
        return False
    return a.val == b.val and is_mirror(a.left, b.right) and is_mirror(a.right, b.left)

def is_symmetric(root: Optional[TreeNode]) -> bool:
    if not root:
        return True
    return is_mirror(root.left, root.right)

def build_example1():
    r = TreeNode(1)
    r.left = TreeNode(2)
    r.right = TreeNode(2)
    r.left.left = TreeNode(3)
    r.left.right = TreeNode(4)
    r.right.left = TreeNode(4)
    r.right.right = TreeNode(3)
    return r

def build_example2():
    r = TreeNode(1)
    r.left = TreeNode(2)
    r.right = TreeNode(2)
    r.left.right = TreeNode(3)
    r.right.right = TreeNode(3)
    return r

if __name__ == '__main__':
    a = build_example1()
    b = build_example2()
    print('Example1 is symmetric:', is_symmetric(a))  # True
    print('Example2 is symmetric:', is_symmetric(b))  # False
    print('Empty tree symmetric:', is_symmetric(None))

# Time Complexity: O(n)
# Space Complexity: O(h) recursion stack where h is tree height
