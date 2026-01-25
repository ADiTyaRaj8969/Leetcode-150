"""
Copy List with Random Pointer

Create a deep copy of a linked list where each node has a next and random pointer.
Approach: use dictionary mapping original -> copy.
"""

class Node:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.random = None

def copy_random_list(head: 'Node') -> 'Node':
    if not head: return None
    old_to_new = {}
    cur = head
    while cur:
        old_to_new[cur] = Node(cur.val)
        cur = cur.next
    cur = head
    while cur:
        copy = old_to_new[cur]
        copy.next = old_to_new.get(cur.next)
        copy.random = old_to_new.get(cur.random)
        cur = cur.next
    return old_to_new[head]

def print_list(head: 'Node'):
    cur = head
    out = []
    while cur:
        r = cur.random.val if cur.random else None
        out.append(f"({cur.val}, rand={r})")
        cur = cur.next
    print(' -> '.join(out))


if __name__ == '__main__':
    n1 = Node(7); n2 = Node(13); n3 = Node(11)
    n1.next = n2; n2.next = n3
    n1.random = None; n2.random = n1; n3.random = n1
    print('Original:', end=' '); print_list(n1)
    c = copy_random_list(n1)
    print('Copied:  ', end=' '); print_list(c)

# Time Complexity: O(n)
# Space Complexity: O(n)
