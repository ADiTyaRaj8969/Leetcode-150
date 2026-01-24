"""
Rotate Image

Rotate an n x n 2D matrix by 90 degrees clockwise, in-place.
"""

from typing import List

def rotate(matrix: List[List[int]]) -> None:
    n = len(matrix)
    # transpose
    for i in range(n):
        for j in range(i+1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    # reverse each row
    for i in range(n):
        matrix[i].reverse()


if __name__ == '__main__':
    m = [[1,2,3],[4,5,6],[7,8,9]]
    rotate(m)
    print('Rotated:')
    for r in m: print(r)

# Time Complexity: O(n^2)
# Space Complexity: O(1)
