/*
Container With Most Water

Given n non-negative integers representing heights, find two lines that together with the x-axis form a container holding the most water.

Strategy: Two-pointer approach moving the smaller side inward.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int h = min(height[l], height[r]);
        ans = max(ans, h * (r - l));
        if (height[l] < height[r]) ++l; else --r;
    }
    return ans;
}

int main() {
    vector<int> a1 = {1,8,6,2,5,4,8,3,7};
    cout << "Container 1: " << maxArea(a1) << '\n'; // 49
    vector<int> a2 = {1,1};
    cout << "Container 2: " << maxArea(a2) << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
