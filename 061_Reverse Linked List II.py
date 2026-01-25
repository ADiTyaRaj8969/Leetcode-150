"""
Reverse Linked List II

Reverse the nodes of a linked list from position left to right (1-indexed).
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def reverse_between(head: ListNode, left: int, right: int) -> ListNode:
    if not head or left == right: return head
    dummy = ListNode(0); dummy.next = head
    prev = dummy
    for _ in range(left-1): prev = prev.next
    cur = prev.next
    for _ in range(right-left):
        tmp = cur.next
        cur.next = tmp.next
        tmp.next = prev.next
        prev.next = tmp
    return dummy.next

def print_list(h: ListNode):
    out = []
    while h:
        out.append(str(h.val)); h = h.next
    print(' '.join(out))

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(3); a.next.next.next = ListNode(4); a.next.next.next.next = ListNode(5)
    print('RevII 1:', end=' '); print_list(reverse_between(a,2,4))
    b = ListNode(5)
    print('RevII 2:', end=' '); print_list(reverse_between(b,1,1))

# Time Complexity: O(n)
# Space Complexity: O(1)
