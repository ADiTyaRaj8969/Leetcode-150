"""
Remove Nth Node From End of List

Remove the n-th node from the end of a linked list and return its head.
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def remove_nth_from_end(head: ListNode, n: int) -> ListNode:
    dummy = ListNode(0); dummy.next = head
    first = dummy; second = dummy
    for _ in range(n+1):
        first = first.next
    while first:
        first = first.next; second = second.next
    to_del = second.next
    second.next = to_del.next
    return dummy.next

def print_list(h: ListNode):
    out = []
    while h:
        out.append(str(h.val)); h = h.next
    print(' '.join(out))

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(3); a.next.next.next = ListNode(4); a.next.next.next.next = ListNode(5)
    print('RemoveNth 1:', end=' '); print_list(remove_nth_from_end(a,2))
    b = ListNode(1)
    print('RemoveNth 2:', end=' '); print_list(remove_nth_from_end(b,1))

# Time Complexity: O(n)
# Space Complexity: O(1)
