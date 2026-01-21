"""
Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in-place and return the new length.
Do not allocate extra space for another array; modify the input array in-place with O(1) extra memory.

Strategy: Two-pointer overwrite.
"""

from typing import List

def remove_element(nums: List[int], val: int) -> int:
    k = 0
    for x in nums:
        if x != val:
            nums[k] = x
            k += 1
    return k


if __name__ == '__main__':
    # Test 1
    a1 = [3,2,2,3]
    k1 = remove_element(a1, 3)
    print(f"New len 1: {k1}, arr: {a1[:k1]}")

    # Test 2
    a2 = [0,1,2,2,3,0,4,2]
    k2 = remove_element(a2, 2)
    print(f"New len 2: {k2}, arr: {a2[:k2]}")

    # Test 3
    a3 = [1,1,1]
    k3 = remove_element(a3, 1)
    print(f"New len 3: {k3}, arr: {a3[:k3]}")

# Time Complexity: O(n)
# Space Complexity: O(1)
