/*
Spiral Matrix

Return all elements of an m x n matrix in spiral order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int r1 = 0, r2 = matrix.size() - 1;
    int c1 = 0, c2 = matrix[0].size() - 1;
    vector<int> res;
    while (r1 <= r2 && c1 <= c2) {
        for (int c = c1; c <= c2; ++c) res.push_back(matrix[r1][c]);
        for (int r = r1 + 1; r <= r2; ++r) res.push_back(matrix[r][c2]);
        if (r1 < r2 && c1 < c2) {
            for (int c = c2 - 1; c > c1; --c) res.push_back(matrix[r2][c]);
            for (int r = r2; r > r1; --r) res.push_back(matrix[r][c1]);
        }
        ++r1; --r2; ++c1; --c2;
    }
    return res;
}

int main() {
    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = spiralOrder(m1);
    cout << "Spiral 1:";
    for (int v: r1) cout << ' ' << v;
    cout << endl; // 1 2 3 6 9 8 7 4 5

    vector<vector<int>> m2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto r2 = spiralOrder(m2);
    cout << "Spiral 2:";
    for (int v: r2) cout << ' ' << v;
    cout << endl;
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(1) extra (output excluded)
