"""
Partition List

Partition a linked list around value x, preserving relative order.
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def partition(head: ListNode, x: int) -> ListNode:
    before = ListNode(0); after = ListNode(0)
    b, a = before, after
    while head:
        if head.val < x:
            b.next = head; b = b.next
        else:
            a.next = head; a = a.next
        head = head.next
    a.next = None
    b.next = after.next
    return before.next

def print_list(h: ListNode):
    out = []
    while h:
        out.append(str(h.val)); h = h.next
    print(' '.join(out))

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(4); a.next.next = ListNode(3); a.next.next.next = ListNode(2); a.next.next.next.next = ListNode(5); a.next.next.next.next.next = ListNode(2)
    print('Partition:', end=' '); print_list(partition(a,3))

# Time Complexity: O(n)
# Space Complexity: O(1)
