"""
Game of Life

Compute the next state of Conway's Game of Life grid. In-place using 2-bit encoding.
"""

from typing import List

def game_of_life(board: List[List[int]]) -> None:
    m = len(board)
    if m == 0: return
    n = len(board[0])
    dirs = [-1,0,1]
    for i in range(m):
        for j in range(n):
            live = 0
            for di in dirs:
                for dj in dirs:
                    if di==0 and dj==0: continue
                    ni, nj = i+di, j+dj
                    if 0 <= ni < m and 0 <= nj < n:
                        live += board[ni][nj] & 1
            if board[i][j] & 1:
                if live == 2 or live == 3:
                    board[i][j] |= 2
            else:
                if live == 3:
                    board[i][j] |= 2
    for i in range(m):
        for j in range(n):
            board[i][j] >>= 1


if __name__ == '__main__':
    b = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    game_of_life(b)
    print('Game of Life next state:')
    for r in b: print(r)

# Time Complexity: O(m*n)
# Space Complexity: O(1)
