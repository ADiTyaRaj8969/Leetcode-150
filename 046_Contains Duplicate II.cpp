/*
Contains Duplicate II

Given an integer array nums and an integer k, return true if there are
two distinct indices i and j such that nums[i] == nums[j] and abs(i - j) <= k.
*/

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (mp.count(nums[i]) && i - mp[nums[i]] <= k) {
            return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> n1 = {1,2,3,1};
    cout << "Test 1: " << (containsNearbyDuplicate(n1, 3) ? "true" : "false") << endl; // true

    vector<int> n2 = {1,0,1,1};
    cout << "Test 2: " << (containsNearbyDuplicate(n2, 1) ? "true" : "false") << endl; // true

    vector<int> n3 = {1,2,3,1,2,3};
    cout << "Test 3: " << (containsNearbyDuplicate(n3, 2) ? "true" : "false") << endl; // false
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(min(n, k))
