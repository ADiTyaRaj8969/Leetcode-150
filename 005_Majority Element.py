"""
Majority Element

Given an array of size n, find the majority element which appears more than n/2 times.
Assume the majority element always exists.

Strategy: Boyer-Moore Voting Algorithm.
"""

from typing import List

def majority_element(nums: List[int]) -> int:
    count = 0
    candidate = None
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate


if __name__ == '__main__':
    print('Majority 1:', majority_element([3,2,3]))
    print('Majority 2:', majority_element([2,2,1,1,1,2,2]))
    print('Majority 3:', majority_element([1]))

# Time Complexity: O(n)
# Space Complexity: O(1)
