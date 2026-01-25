/*
Minimum Number of Arrows to Burst Balloons

Given a set of intervals representing balloons, find the minimum number of arrows
that must be shot to burst all balloons. Greedy by sorting intervals by end.
*/

#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<pair<int,int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](const auto &a, const auto &b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int arrows = 1;
    int curEnd = points[0].second;
    for (int i = 1; i < (int)points.size(); ++i) {
        if (points[i].first > curEnd) {
            arrows++;
            curEnd = points[i].second;
        }
    }
    return arrows;
}

int main() {
    vector<pair<int,int>> p1 = {{10,16},{2,8},{1,6},{7,12}};
    cout << "Arrows 1: " << findMinArrowShots(p1) << endl; // 2

    vector<pair<int,int>> p2 = {{1,2},{3,4},{5,6},{7,8}};
    cout << "Arrows 2: " << findMinArrowShots(p2) << endl; // 4

    vector<pair<int,int>> p3 = {{1,2},{2,3},{3,4},{4,5}};
    cout << "Arrows 3: " << findMinArrowShots(p3) << endl; // 2
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1)
