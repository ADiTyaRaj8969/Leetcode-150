"""
Rotate Array

Rotate an array to the right by k steps, where k is non-negative.

Strategy: Reverse the whole array, then reverse first k, then reverse remaining.
"""

from typing import List

def rotate(nums: List[int], k: int) -> None:
    n = len(nums)
    if n == 0:
        return
    k %= n
    if k == 0:
        return
    nums.reverse()
    nums[:k] = reversed(nums[:k])
    nums[k:] = reversed(nums[k:])


if __name__ == '__main__':
    a1 = [1,2,3,4,5,6,7]
    rotate(a1, 3)
    print('Rotated 1:', a1)

    a2 = [-1,-100,3,99]
    rotate(a2, 2)
    print('Rotated 2:', a2)

    a3 = [1,2]
    rotate(a3, 0)
    print('Rotated 3:', a3)

# Time Complexity: O(n)
# Space Complexity: O(1)
