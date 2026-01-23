/*
3Sum

Find all unique triplets in the array which gives the sum of zero.

Strategy: Sort and use two-pointer for each fixed first element, skip duplicates.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int target = -nums[i];
        int l = i+1, r = n-1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) ++l;
                while (l < r && nums[r] == nums[r-1]) --r;
                ++l; --r;
            } else if (sum < target) ++l; else --r;
        }
    }
    return res;
}

int main() {
    vector<int> a1 = {-1,0,1,2,-1,-4};
    auto r1 = threeSum(a1);
    cout << "3Sum 1:\n";
    for (auto &v : r1) cout << '[' << v[0] << ',' << v[1] << ',' << v[2] << ']' << '\n';
    vector<int> a2 = {0,0,0,0};
    auto r2 = threeSum(a2);
    cout << "3Sum 2:\n";
    for (auto &v : r2) cout << '[' << v[0] << ',' << v[1] << ',' << v[2] << ']' << '\n';
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(log n) for sorting or O(n) depending on sort implementation
*/
