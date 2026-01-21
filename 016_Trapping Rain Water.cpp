/*
Trapping Rain Water

Given an elevation map (array of heights), compute how much water it can trap after raining.

Strategy: Two-pointer approach tracking left_max and right_max — O(n) time, O(1) space.
*/

#include <vector>
#include <iostream>
using namespace std;

int trap(const vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    while (l <= r) {
        if (height[l] <= height[r]) {
            if (height[l] >= leftMax) leftMax = height[l];
            else ans += leftMax - height[l];
            ++l;
        } else {
            if (height[r] >= rightMax) rightMax = height[r];
            else ans += rightMax - height[r];
            --r;
        }
    }
    return ans;
}

int main() {
    cout << "Trap 1: " << trap({0,1,0,2,1,0,1,3,2,1,2,1}) << '\n'; // 6
    cout << "Trap 2: " << trap({4,2,0,3,2,5}) << '\n'; // 9
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
