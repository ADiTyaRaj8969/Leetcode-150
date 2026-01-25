"""
Summary Ranges

Given a sorted unique integer array nums, return the smallest sorted list of ranges
that cover all the numbers in the array exactly.
"""

def summaryRanges(nums: list[int]) -> list[str]:
    if not nums:
        return []
    
    result = []
    start = end = nums[0]
    
    for i in range(1, len(nums)):
        if nums[i] == end + 1:
            end = nums[i]
        else:
            if start == end:
                result.append(str(start))
            else:
                result.append(f"{start}->{end}")
            start = end = nums[i]
    
    # Add the last range
    if start == end:
        result.append(str(start))
    else:
        result.append(f"{start}->{end}")
    
    return result

if __name__ == "__main__":
    print("Test 1:", summaryRanges([0, 1, 2, 4, 5, 7]))  # ["0->2","4->5","7"]
    print("Test 2:", summaryRanges([0, 2, 3, 4, 6, 8, 9]))  # ["0","2->4","6","8->9"]

# Time Complexity: O(n)
# Space Complexity: O(1) excluding output
