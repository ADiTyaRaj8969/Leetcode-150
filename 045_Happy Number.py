"""
Happy Number

Determine if a number is happy: repeatedly replace number with sum of squares of digits;
if it becomes 1 it's happy; detect cycles otherwise.
"""

def next_num(n: int) -> int:
    s = 0
    while n:
        d = n % 10
        s += d*d
        n //= 10
    return s

def is_happy(n: int) -> bool:
    slow = n
    fast = n
    while True:
        slow = next_num(slow)
        fast = next_num(next_num(fast))
        if slow == fast:
            break
    return slow == 1


if __name__ == '__main__':
    print('Happy 1:', is_happy(19))
    print('Happy 2:', is_happy(2))

# Time Complexity: O(log n) per iteration, overall amortized O(1)
# Space Complexity: O(1)
