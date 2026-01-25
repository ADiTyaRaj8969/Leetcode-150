"""
Reverse Nodes in k-Group

Reverse nodes of a linked list k at a time and return the modified list.
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def reverse_k_group(head: ListNode, k: int) -> ListNode:
    dummy = ListNode(0); dummy.next = head
    group_prev = dummy
    while True:
        kth = group_prev
        for _ in range(k):
            kth = kth.next
            if not kth:
                return dummy.next
        group_next = kth.next
        prev = group_next
        cur = group_prev.next
        while cur is not group_next:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        tmp = group_prev.next
        group_prev.next = kth
        group_prev = tmp

def print_list(h: ListNode):
    vals = []
    while h:
        vals.append(str(h.val)); h = h.next
    print(' '.join(vals))

if __name__ == '__main__':
    a = ListNode(1); a.next = ListNode(2); a.next.next = ListNode(3); a.next.next.next = ListNode(4); a.next.next.next.next = ListNode(5)
    print('KGroup 1:', end=' '); print_list(reverse_k_group(a,2))
    b = ListNode(1); b.next = ListNode(2); b.next.next = ListNode(3)
    print('KGroup 2:', end=' '); print_list(reverse_k_group(b,3))

# Time Complexity: O(n)
# Space Complexity: O(1)
