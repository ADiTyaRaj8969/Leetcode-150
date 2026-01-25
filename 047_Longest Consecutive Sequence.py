"""
Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence. Must run in O(n) time.
"""

def longestConsecutive(nums: list[int]) -> int:
    num_set = set(nums)
    longest = 0
    
    for num in num_set:
        # Only start counting if num is the start of a sequence
        if num - 1 not in num_set:
            current_num = num
            current_streak = 1
            
            while current_num + 1 in num_set:
                current_num += 1
                current_streak += 1
            
            longest = max(longest, current_streak)
    
    return longest

if __name__ == "__main__":
    print("Test 1:", longestConsecutive([100, 4, 200, 1, 3, 2]))  # 4
    print("Test 2:", longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]))  # 9
    print("Test 3:", longestConsecutive([]))  # 0

# Time Complexity: O(n)
# Space Complexity: O(n)
