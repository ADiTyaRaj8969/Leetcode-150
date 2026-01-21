"""
Jump Game

Given an array of non-negative integers nums, where nums[i] is the max jump length from that position, determine if you can reach the last index.

Strategy: Greedy — maintain farthest reachable index.
"""

from typing import List

def can_jump(nums: List[int]) -> bool:
    reachable = 0
    for i, step in enumerate(nums):
        if i > reachable:
            return False
        reachable = max(reachable, i + step)
        if reachable >= len(nums) - 1:
            return True
    return True


if __name__ == '__main__':
    print('CanJump 1:', can_jump([2,3,1,1,4]))
    print('CanJump 2:', can_jump([3,2,1,0,4]))
    print('CanJump 3:', can_jump([0]))

# Time Complexity: O(n)
# Space Complexity: O(1)
