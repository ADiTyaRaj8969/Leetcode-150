"""
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new sorted list.
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def merge_two_lists(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    tail = dummy
    while l1 and l2:
        if l1.val < l2.val:
            tail.next = l1; l1 = l1.next
        else:
            tail.next = l2; l2 = l2.next
        tail = tail.next
    tail.next = l1 or l2
    return dummy.next

def print_list(node: ListNode):
    vals = []
    while node:
        vals.append(str(node.val)); node = node.next
    print(' '.join(vals))


if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(4)
    b = ListNode(1); b.next = ListNode(3); b.next.next = ListNode(4)
    r = merge_two_lists(a,b)
    print('Merged:', end=' '); print_list(r)

# Time Complexity: O(m+n)
# Space Complexity: O(1)
