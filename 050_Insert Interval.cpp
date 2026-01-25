/*
Insert Interval

Given a set of non-overlapping intervals sorted by start time, insert a new interval
into the intervals (merge if necessary) and return the result.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0;
    int n = intervals.size();
    
    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }
    
    // Merge overlapping intervals with new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}

int main() {
    vector<vector<int>> i1 = {{1,3},{6,9}};
    vector<int> n1 = {2,5};
    auto r1 = insert(i1, n1);
    cout << "Test 1: ";
    for (auto& v : r1) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // [[1,5],[6,9]]

    vector<vector<int>> i2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> n2 = {4,8};
    auto r2 = insert(i2, n2);
    cout << "Test 2: ";
    for (auto& v : r2) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // [[1,2],[3,10],[12,16]]
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
