"""
Linked List Cycle

Determine if a linked list has a cycle using Floyd's cycle detection.
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def has_cycle(head: ListNode) -> bool:
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False


if __name__ == '__main__':
    a = ListNode(3)
    b = ListNode(2)
    c = ListNode(0)
    d = ListNode(-4)
    a.next = b; b.next = c; c.next = d; d.next = b
    print('Cycle 1:', has_cycle(a))

    x = ListNode(1); y = ListNode(2)
    x.next = y; y.next = None
    print('Cycle 2:', has_cycle(x))

# Time Complexity: O(n)
# Space Complexity: O(1)
