/*
Two Sum

Find indices of two numbers that add up to a specific target.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];
        if (m.count(need)) return {m[need], i};
        m[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> a1 = {2,7,11,15};
    auto r1 = twoSum(a1, 9);
    cout << "TwoSum 1:";
    for (int x: r1) cout << ' ' << x;
    cout << endl; // 0 1

    vector<int> a2 = {3,2,4};
    auto r2 = twoSum(a2, 6);
    cout << "TwoSum 2:";
    for (int x: r2) cout << ' ' << x;
    cout << endl; // 1 2
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
