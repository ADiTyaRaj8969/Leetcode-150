"""
Invert Binary Tree

Invert a binary tree by swapping left and right children for all nodes.
"""

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

def invert_tree(root: TreeNode) -> TreeNode:
    if not root: return None
    root.left, root.right = root.right, root.left
    invert_tree(root.left)
    invert_tree(root.right)
    return root

def print_pre(r: TreeNode):
    if not r: return
    print(r.val, end=' ')
    print_pre(r.left); print_pre(r.right)

if __name__ == '__main__':
    root = TreeNode(4)
    root.left = TreeNode(2); root.right = TreeNode(7)
    root.left.left = TreeNode(1); root.left.right = TreeNode(3)
    root.right.left = TreeNode(6); root.right.right = TreeNode(9)
    invert_tree(root)
    print('Inverted preorder:', end=' '); print_pre(root); print()

# Time Complexity: O(n)
# Space Complexity: O(h)
