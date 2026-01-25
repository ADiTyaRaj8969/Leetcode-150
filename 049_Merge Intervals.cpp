/*
Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals and return an array of the non-overlapping intervals.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    
    for (int i = 1; i < (int)intervals.size(); ++i) {
        if (intervals[i][0] <= result.back()[1]) {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> i1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = merge(i1);
    cout << "Test 1: ";
    for (auto& v : r1) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // [[1,6],[8,10],[15,18]]

    vector<vector<int>> i2 = {{1,4},{4,5}};
    auto r2 = merge(i2);
    cout << "Test 2: ";
    for (auto& v : r2) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // [[1,5]]
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
