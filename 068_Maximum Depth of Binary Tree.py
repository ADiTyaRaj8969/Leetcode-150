"""
Maximum Depth of Binary Tree

Find the maximum depth (longest root-to-leaf path) of a binary tree.
"""

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

def max_depth(root: TreeNode) -> int:
    if not root: return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print('MaxDepth:', max_depth(root))

# Time Complexity: O(n)
# Space Complexity: O(h)
