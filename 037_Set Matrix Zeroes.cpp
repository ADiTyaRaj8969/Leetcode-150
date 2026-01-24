/*
Set Matrix Zeroes

If an element in an m x n matrix is 0, set its entire row and column to 0 in-place.
*/

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;
    for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) firstCol = true;
    for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) firstRow = true;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    if (firstCol) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    if (firstRow) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
}

int main() {
    vector<vector<int>> a = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(a);
    cout << "Zeroes 1:" << endl;
    for (auto &r: a) { for (int v: r) cout << v << ' '; cout << endl; }

    vector<vector<int>> b = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(b);
    cout << "Zeroes 2:" << endl;
    for (auto &r: b) { for (int v: r) cout << v << ' '; cout << endl; }
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(1)
