"""
Minimum Size Subarray Sum

Find minimal length of contiguous subarray with sum >= target.
"""

from typing import List

def min_sub_array_len(target: int, nums: List[int]) -> int:
    n = len(nums)
    l = 0
    s = 0
    ans = float('inf')
    for r in range(n):
        s += nums[r]
        while s >= target:
            ans = min(ans, r - l + 1)
            s -= nums[l]
            l += 1
    return 0 if ans == float('inf') else ans


if __name__ == '__main__':
    print('MinSub 1:', min_sub_array_len(7, [2,3,1,2,4,3]))
    print('MinSub 2:', min_sub_array_len(4, [1,4,4]))
    print('MinSub 3:', min_sub_array_len(11, [1,2,3,4,5]))

# Time Complexity: O(n)
# Space Complexity: O(1)
