"""
Jump Game II

Given an array of non-negative integers nums, where nums[i] is the max jump length from that position, return the minimum number of jumps to reach the last index.

Strategy: Greedy — expand current reachable window and count jumps when window ends.
"""

from typing import List

def jump(nums: List[int]) -> int:
    n = len(nums)
    if n <= 1:
        return 0
    jumps = 0
    current_end = 0
    farthest = 0
    for i in range(n - 1):
        farthest = max(farthest, i + nums[i])
        if i == current_end:
            jumps += 1
            current_end = farthest
            if current_end >= n - 1:
                break
    return jumps


if __name__ == '__main__':
    print('JumpMin 1:', jump([2,3,1,1,4]))
    print('JumpMin 2:', jump([2,3,0,1,4]))
    print('JumpMin 3:', jump([0]))

# Time Complexity: O(n)
# Space Complexity: O(1)

