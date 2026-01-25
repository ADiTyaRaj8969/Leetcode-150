"""
Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals and return an array of the non-overlapping intervals.
"""

def merge(intervals: list[list[int]]) -> list[list[int]]:
    if not intervals:
        return []
    
    intervals.sort()
    result = [intervals[0]]
    
    for i in range(1, len(intervals)):
        if intervals[i][0] <= result[-1][1]:
            result[-1][1] = max(result[-1][1], intervals[i][1])
        else:
            result.append(intervals[i])
    
    return result

if __name__ == "__main__":
    print("Test 1:", merge([[1,3],[2,6],[8,10],[15,18]]))  # [[1,6],[8,10],[15,18]]
    print("Test 2:", merge([[1,4],[4,5]]))  # [[1,5]]

# Time Complexity: O(n log n)
# Space Complexity: O(n)
