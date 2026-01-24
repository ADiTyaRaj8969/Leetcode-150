/*
Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated
according to the rules: each row, column, and 3x3 sub-box must contain digits 1-9 without repetition.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<array<bool,9>> rows(9), cols(9), boxes(9);
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
        char c = board[i][j];
        if (c == '.') continue;
        int v = c - '1';
        if (rows[i][v] || cols[j][v] || boxes[(i/3)*3 + j/3][v]) return false;
        rows[i][v] = cols[j][v] = boxes[(i/3)*3 + j/3][v] = true;
    }
    return true;
}

int main() {
    vector<vector<char>> b1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << "Sudoku 1: " << (isValidSudoku(b1) ? "true" : "false") << endl; // true

    vector<vector<char>> b2 = b1;
    b2[0][0] = '8';
    cout << "Sudoku 2: " << (isValidSudoku(b2) ? "true" : "false") << endl; // false
    return 0;
}

// Time Complexity: O(1) (9x9 fixed)
// Space Complexity: O(1)
