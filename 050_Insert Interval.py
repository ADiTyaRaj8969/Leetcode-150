"""
Insert Interval

Given a set of non-overlapping intervals sorted by start time, insert a new interval
into the intervals (merge if necessary) and return the result.
"""

def insert(intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
    result = []
    i = 0
    n = len(intervals)
    
    # Add all intervals that come before the new interval
    while i < n and intervals[i][1] < newInterval[0]:
        result.append(intervals[i])
        i += 1
    
    # Merge overlapping intervals with new interval
    while i < n and intervals[i][0] <= newInterval[1]:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i += 1
    result.append(newInterval)
    
    # Add remaining intervals
    while i < n:
        result.append(intervals[i])
        i += 1
    
    return result

if __name__ == "__main__":
    print("Test 1:", insert([[1,3],[6,9]], [2,5]))  # [[1,5],[6,9]]
    print("Test 2:", insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]))  # [[1,2],[3,10],[12,16]]

# Time Complexity: O(n)
# Space Complexity: O(n)
