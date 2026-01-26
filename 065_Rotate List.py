"""
Rotate List

Rotate a linked list to the right by k places.
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def rotate_right(head: ListNode, k: int) -> ListNode:
    if not head or not head.next or k == 0: return head
    n = 1
    tail = head
    while tail.next:
        tail = tail.next; n += 1
    k %= n
    if k == 0: return head
    tail.next = head
    steps = n - k
    new_tail = tail
    for _ in range(steps): new_tail = new_tail.next
    new_head = new_tail.next
    new_tail.next = None
    return new_head

def print_list(h: ListNode):
    out = []
    while h:
        out.append(str(h.val)); h = h.next
    print(' '.join(out))

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(3); a.next.next.next = ListNode(4); a.next.next.next.next = ListNode(5)
    print('RotateList 1:', end=' '); print_list(rotate_right(a,2))
    b = ListNode(0); b.next = ListNode(1)
    print('RotateList 2:', end=' '); print_list(rotate_right(b,4))

# Time Complexity: O(n)
# Space Complexity: O(1)
