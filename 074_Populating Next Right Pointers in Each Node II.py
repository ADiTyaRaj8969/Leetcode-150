"""
Populating Next Right Pointers in Each Node II
Populate each node's next pointer to its next right node in a binary tree (any shape).
"""
from typing import Optional

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        head = root
        while head:
            dummy = Node(0)
            tail = dummy
            p = head
            while p:
                if p.left:
                    tail.next = p.left
                    tail = tail.next
                if p.right:
                    tail.next = p.right
                    tail = tail.next
                p = p.next
            head = dummy.next
        return root

def print_levels_with_next(root: Node):
    level = root
    while level:
        cur = level
        row = []
        while cur:
            row.append(cur.val)
            cur = cur.next
        print(row)
        # find next level head
        nxt = None
        p = level
        while p and not nxt:
            nxt = p.left or p.right
            p = p.next
        level = nxt

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(5)
    root.right.right = Node(4)
    Solution().connect(root)
    print_levels_with_next(root)

# Time Complexity: O(n)
# Space Complexity: O(1) extra
