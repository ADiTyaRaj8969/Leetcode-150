/*
Jump Game

Given an array of non-negative integers nums, where nums[i] represents the maximum jump length from that position, determine if you can reach the last index starting from the first index.

Strategy: Greedy keep track of farthest reachable index.
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

bool canJump(const vector<int>& nums) {
    int reachable = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > reachable) return false;
        reachable = max(reachable, i + nums[i]);
        if (reachable >= (int)nums.size() - 1) return true;
    }
    return false;
}


int main() {
    cout << boolalpha;
    cout << "CanJump 1: " << canJump({2,3,1,1,4}) << '\n';
    cout << "CanJump 2: " << canJump({3,2,1,0,4}) << '\n';
    cout << "CanJump 3: " << canJump({0}) << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
