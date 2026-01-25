"""
Contains Duplicate II

Given an integer array nums and an integer k, return true if there are
two distinct indices i and j such that nums[i] == nums[j] and abs(i - j) <= k.
"""

def containsNearbyDuplicate(nums: list[int], k: int) -> bool:
    mp = {}
    for i, num in enumerate(nums):
        if num in mp and i - mp[num] <= k:
            return True
        mp[num] = i
    return False

if __name__ == "__main__":
    print("Test 1:", containsNearbyDuplicate([1,2,3,1], 3))  # True
    print("Test 2:", containsNearbyDuplicate([1,0,1,1], 1))  # True
    print("Test 3:", containsNearbyDuplicate([1,2,3,1,2,3], 2))  # False

# Time Complexity: O(n)
# Space Complexity: O(min(n, k))
