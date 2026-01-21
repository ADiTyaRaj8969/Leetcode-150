"""
Remove Duplicates from Sorted Array II

Given a sorted array nums, remove the duplicates in-place such that duplicates are allowed at most twice.
Return the new length after removal.

Strategy: Two-pointer allowing up to two occurrences by comparing to nums[k-2].
"""

from typing import List

def remove_duplicates(nums: List[int]) -> int:
    n = len(nums)
    if n <= 2:
        return n
    k = 2
    for i in range(2, n):
        if nums[i] != nums[k-2]:
            nums[k] = nums[i]
            k += 1
    return k


if __name__ == '__main__':
    a1 = [1,1,1,2,2,3]
    k1 = remove_duplicates(a1)
    print(f"New len 1: {k1}, arr: {a1[:k1]}")

    a2 = [0,0,0,0,1,1,1]
    k2 = remove_duplicates(a2)
    print(f"New len 2: {k2}, arr: {a2[:k2]}")

    a3 = [1,2]
    k3 = remove_duplicates(a3)
    print(f"New len 3: {k3}, arr: {a3[:k3]}")

# Time Complexity: O(n)
# Space Complexity: O(1)
