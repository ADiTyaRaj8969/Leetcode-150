"""
Set Matrix Zeroes

If an element in an m x n matrix is 0, set its entire row and column to 0 in-place.
"""

from typing import List

def set_zeroes(matrix: List[List[int]]) -> None:
    m, n = len(matrix), len(matrix[0])
    first_row = any(matrix[0][j] == 0 for j in range(n))
    first_col = any(matrix[i][0] == 0 for i in range(m))
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][0] == 0 or matrix[0][j] == 0:
                matrix[i][j] = 0
    if first_row:
        for j in range(n): matrix[0][j] = 0
    if first_col:
        for i in range(m): matrix[i][0] = 0


if __name__ == '__main__':
    a = [[1,1,1],[1,0,1],[1,1,1]]
    set_zeroes(a)
    print('Zeroes 1:')
    for r in a: print(r)

    b = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    set_zeroes(b)
    print('Zeroes 2:')
    for r in b: print(r)

# Time Complexity: O(m*n)
# Space Complexity: O(1)
