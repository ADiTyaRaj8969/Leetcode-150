/*
Jump Game II

Given an array of non-negative integers nums, where nums[i] is the max jump length from that position, return the minimum number of jumps to reach the last index.

Strategy: Greedy BFS-like level expansion. Track current range and next farthest.
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int jump(const vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == current_end) {
            ++jumps;
            current_end = farthest;
            if (current_end >= n - 1) break;
        }
    }
    return jumps;
}


int main() {
    cout << "JumpMin 1: " << jump({2,3,1,1,4}) << '\n';
    cout << "JumpMin 2: " << jump({2,3,0,1,4}) << '\n';
    cout << "JumpMin 3: " << jump({0}) << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
