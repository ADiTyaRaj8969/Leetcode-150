"""
Trapping Rain Water

Compute how much water can be trapped given an elevation map.
"""

from typing import List

def trap(height: List[int]) -> int:
    l, r = 0, len(height) - 1
    leftMax = rightMax = 0
    ans = 0
    while l <= r:
        if height[l] <= height[r]:
            if height[l] >= leftMax:
                leftMax = height[l]
            else:
                ans += leftMax - height[l]
            l += 1
        else:
            if height[r] >= rightMax:
                rightMax = height[r]
            else:
                ans += rightMax - height[r]
            r -= 1
    return ans


if __name__ == '__main__':
    print('Trap 1:', trap([0,1,0,2,1,0,1,3,2,1,2,1]))
    print('Trap 2:', trap([4,2,0,3,2,5]))

# Time Complexity: O(n)
# Space Complexity: O(1)
