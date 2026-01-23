/*
Minimum Size Subarray Sum

Find minimal length of contiguous subarray with sum >= target.
*/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 0, sum = 0, ans = INT_MAX;
    for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum >= target) {
            ans = min(ans, r - l + 1);
            sum -= nums[l++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    vector<int> a1 = {2,3,1,2,4,3};
    cout << "MinSub 1: " << minSubArrayLen(7, a1) << endl; // 2

    vector<int> a2 = {1,4,4};
    cout << "MinSub 2: " << minSubArrayLen(4, a2) << endl; // 1

    vector<int> a3 = {1,2,3,4,5};
    cout << "MinSub 3: " << minSubArrayLen(11, a3) << endl; // 3
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
/*
Minimum Size Subarray Sum

Given an array of positive integers and a target, find the minimal length of a contiguous subarray of which the sum >= target. Return 0 if none.

Strategy: Sliding window two-pointer since numbers are positive.
*/

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
    int n = nums.size();
    int l = 0, sum = 0, ans = INT_MAX;
    for (int r = 0; r < n; ++r) {
        sum += nums[r];
        while (sum >= target) {
            ans = min(ans, r - l + 1);
            sum -= nums[l++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main() {
    cout << "MinSub 1: " << minSubArrayLen(7, {2,3,1,2,4,3}) << '\n'; // 2
    cout << "MinSub 2: " << minSubArrayLen(4, {1,4,4}) << '\n'; // 1
    cout << "MinSub 3: " << minSubArrayLen(11, {1,2,3,4,5}) << '\n'; // 3
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
