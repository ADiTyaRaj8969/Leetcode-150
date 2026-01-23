"""
Container With Most Water

Find max area between two lines using two-pointer greedy.
"""

from typing import List

def max_area(height: List[int]) -> int:
    l, r = 0, len(height) - 1
    ans = 0
    while l < r:
        h = min(height[l], height[r])
        ans = max(ans, h * (r - l))
        if height[l] < height[r]:
            l += 1
        else:
            r -= 1
    return ans


if __name__ == '__main__':
    print('Container 1:', max_area([1,8,6,2,5,4,8,3,7]))
    print('Container 2:', max_area([1,1]))

# Time Complexity: O(n)
# Space Complexity: O(1)
