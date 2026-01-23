"""
Two Sum II - Input Array Is Sorted

Find two numbers (1-indexed) adding to target in sorted array.
"""

from typing import List, Tuple

def two_sum(numbers: List[int], target: int) -> Tuple[int,int]:
    l, r = 0, len(numbers) - 1
    while l < r:
        s = numbers[l] + numbers[r]
        if s == target:
            return (l+1, r+1)
        if s < target:
            l += 1
        else:
            r -= 1
    return (-1,-1)


if __name__ == '__main__':
    print('TwoSumII 1:', two_sum([2,7,11,15], 9))
    print('TwoSumII 2:', two_sum([2,3,4], 6))

# Time Complexity: O(n)
# Space Complexity: O(1)
