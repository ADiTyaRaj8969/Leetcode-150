"""
Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated
according to the rules: each row, column, and 3x3 sub-box must contain digits 1-9 without repetition.
"""

from typing import List

def is_valid_sudoku(board: List[List[str]]) -> bool:
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    for i in range(9):
        for j in range(9):
            c = board[i][j]
            if c == '.':
                continue
            b = (i//3)*3 + j//3
            if c in rows[i] or c in cols[j] or c in boxes[b]:
                return False
            rows[i].add(c); cols[j].add(c); boxes[b].add(c)
    return True


if __name__ == '__main__':
    b1 = [
        ['5','3','.','.','7','.','.','.','.'],
        ['6','.','.','1','9','5','.','.','.'],
        ['.','9','8','.','.','.','.','6','.'],
        ['8','.','.','.','6','.','.','.','3'],
        ['4','.','.','8','.','3','.','.','1'],
        ['7','.','.','.','2','.','.','.','6'],
        ['.','6','.','.','.','.','2','8','.'],
        ['.','.','.','4','1','9','.','.','5'],
        ['.','.','.','.','8','.','.','7','9']
    ]
    print('Sudoku 1:', is_valid_sudoku(b1))
    b2 = [row[:] for row in b1]
    b2[0][0] = '8'
    print('Sudoku 2:', is_valid_sudoku(b2))

# Time Complexity: O(1) (fixed board size)
# Space Complexity: O(1)
