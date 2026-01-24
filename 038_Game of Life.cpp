/*
Game of Life

Compute the next state of Conway's Game of Life grid.
We update in-place using 2-bit encoding: bit0=current, bit1=next.
*/

#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    vector<int> dirs = {-1,0,1};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int live = 0;
            for (int di: dirs) for (int dj: dirs) {
                if (di==0 && dj==0) continue;
                int ni = i + di, nj = j + dj;
                if (ni>=0 && ni<m && nj>=0 && nj<n) live += (board[ni][nj] & 1);
            }
            if (board[i][j] & 1) {
                if (live == 2 || live == 3) board[i][j] |= 2; // stays live
            } else {
                if (live == 3) board[i][j] |= 2; // becomes live
            }
        }
    }
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) board[i][j] >>= 1;
}

int main() {
    vector<vector<int>> b = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(b);
    cout << "Game of Life next state:" << endl;
    for (auto &r: b) { for (int v: r) cout << v << ' '; cout << endl; }
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(1)
