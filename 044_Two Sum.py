"""
Two Sum

Find indices of two numbers that add up to a specific target.
"""

from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    m = {}
    for i, v in enumerate(nums):
        need = target - v
        if need in m:
            return [m[need], i]
        m[v] = i
    return []


if __name__ == '__main__':
    print('TwoSum 1:', two_sum([2,7,11,15], 9))
    print('TwoSum 2:', two_sum([3,2,4], 6))

# Time Complexity: O(n)
# Space Complexity: O(n)
