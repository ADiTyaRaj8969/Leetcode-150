"""
Remove Duplicates from Sorted List II

Delete all nodes that have duplicate numbers from a sorted linked list.
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def delete_duplicates(head: ListNode) -> ListNode:
    dummy = ListNode(0); dummy.next = head
    prev = dummy
    while prev.next:
        curr = prev.next
        dup = False
        while curr.next and curr.val == curr.next.val:
            dup = True
            curr.next = curr.next.next
        if dup:
            prev.next = curr.next
        else:
            prev = prev.next
    return dummy.next

def print_list(h: ListNode):
    print(' '.join(str(x) for x in iter_list(h)))

def iter_list(h: ListNode):
    while h:
        yield h.val; h = h.next

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(3); a.next.next.next = ListNode(3); a.next.next.next.next = ListNode(4)
    print('DelDup 1:', end=' '); print_list(delete_duplicates(a))
    b = ListNode(1); b.next = ListNode(1); b.next.next = ListNode(1); b.next.next.next = ListNode(2); b.next.next.next.next = ListNode(3)
    print('DelDup 2:', end=' '); print_list(delete_duplicates(b))

# Time Complexity: O(n)
# Space Complexity: O(1)
