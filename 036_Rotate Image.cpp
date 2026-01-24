/*
Rotate Image

Rotate an n x n 2D matrix by 90 degrees clockwise, in-place.
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    // reverse each row
    for (int i = 0; i < n; ++i)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(m);
    cout << "Rotated:" << endl;
    for (auto &r: m) {
        for (int v: r) cout << v << ' ';
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
