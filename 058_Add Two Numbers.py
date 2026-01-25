"""
Add Two Numbers

Add two numbers represented by linked lists where digits are stored in reverse order.
Return the sum as a linked list.
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def add_two_numbers(l1: ListNode, l2: ListNode) -> ListNode:
    dummy = ListNode(0)
    cur = dummy
    carry = 0
    while l1 or l2 or carry:
        s = carry
        if l1:
            s += l1.val; l1 = l1.next
        if l2:
            s += l2.val; l2 = l2.next
        cur.next = ListNode(s % 10)
        carry = s // 10
        cur = cur.next
    return dummy.next

def print_list(node: ListNode):
    vals = []
    while node:
        vals.append(str(node.val)); node = node.next
    print(' '.join(vals))


if __name__ == '__main__':
    a = ListNode(2); a.next = ListNode(4); a.next.next = ListNode(3)
    b = ListNode(5); b.next = ListNode(6); b.next.next = ListNode(4)
    r = add_two_numbers(a,b)
    print('Add 1:', end=' '); print_list(r)

    x = ListNode(0); y = ListNode(0)
    print('Add 2:', end=' '); print_list(add_two_numbers(x,y))

# Time Complexity: O(max(m,n))
# Space Complexity: O(max(m,n)) for output
