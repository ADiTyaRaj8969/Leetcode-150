"""
Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and return the new length.
Modify the array in-place with O(1) extra memory.

Strategy: Two-pointer where write pointer keeps unique elements.
"""

from typing import List

def remove_duplicates(nums: List[int]) -> int:
    if not nums:
        return 0
    k = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[k-1]:
            nums[k] = nums[i]
            k += 1
    return k


if __name__ == '__main__':
    a1 = [1,1,2]
    k1 = remove_duplicates(a1)
    print(f"New len 1: {k1}, arr: {a1[:k1]}")

    a2 = [0,0,1,1,1,2,2,3,3,4]
    k2 = remove_duplicates(a2)
    print(f"New len 2: {k2}, arr: {a2[:k2]}")

    a3 = []
    k3 = remove_duplicates(a3)
    print(f"New len 3: {k3}, arr: {a3[:k3]}")

# Time Complexity: O(n)
# Space Complexity: O(1)
