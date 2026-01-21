"""
H-Index

Compute the h-index given a list of citation counts.

Strategy: Sort descending and find largest h where citations[h-1] >= h.
"""

from typing import List

def h_index(citations: List[int]) -> int:
    citations.sort(reverse=True)
    h = 0
    for i, c in enumerate(citations):
        if c >= i + 1:
            h = i + 1
        else:
            break
    return h


if __name__ == '__main__':
    print('H-Index 1:', h_index([3,0,6,1,5]))
    print('H-Index 2:', h_index([10,8,5,4,3]))
    print('H-Index 3:', h_index([0,0,0]))

# Time Complexity: O(n log n)
# Space Complexity: O(1) (in-place sort)
