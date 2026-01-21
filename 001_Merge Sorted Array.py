"""
Merge Sorted Array

Merge two sorted arrays, nums2 into nums1, as one sorted array.
Given two integer arrays nums1 and nums2 sorted in non-decreasing order, and integers m and n representing the number of initialized elements in nums1 and nums2 respectively.
Modify nums1 in-place to be the merged sorted array.

Strategy: Merge from the end to avoid extra memory.
"""

from typing import List

def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    i = m - 1
    j = n - 1
    k = m + n - 1
    while j >= 0:
        if i >= 0 and nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1


def _print(nums: List[int]):
    print(' '.join(map(str, nums)))


if __name__ == '__main__':
    # Test 1
    a1 = [1,2,3,0,0,0]
    b1 = [2,5,6]
    merge(a1, 3, b1, 3)
    print("Merged 1:", end=' '); _print(a1)

    # Test 2
    a2 = [1]
    b2 = []
    merge(a2, 1, b2, 0)
    print("Merged 2:", end=' '); _print(a2)

    # Test 3
    a3 = [0]
    b3 = [1]
    merge(a3, 0, b3, 1)
    print("Merged 3:", end=' '); _print(a3)

# Time Complexity: O(m + n)
# Space Complexity: O(1)
