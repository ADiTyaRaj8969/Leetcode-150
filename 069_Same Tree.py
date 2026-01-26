"""
Same Tree

Check if two binary trees are structurally identical and nodes have the same value.
"""

class TreeNode:
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

def is_same_tree(p: TreeNode, q: TreeNode) -> bool:
    if not p and not q: return True
    if not p or not q: return False
    if p.val != q.val: return False
    return is_same_tree(p.left, q.left) and is_same_tree(p.right, q.right)

if __name__ == '__main__':
    p = TreeNode(1); p.left = TreeNode(2)
    q = TreeNode(1); q.left = TreeNode(2)
    print('Same 1:', is_same_tree(p,q))
    q.left = None; q.right = TreeNode(2)
    print('Same 2:', is_same_tree(p,q))

# Time Complexity: O(min(n,m))
# Space Complexity: O(h)
