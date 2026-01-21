/*
Product of Array Except Self

Given an array nums, return an array answer such that answer[i] is the product of all the elements of nums except nums[i]. Do it without division and in O(n).

Strategy: Compute prefix products then multiply by suffix running product in one pass — O(n), O(1) extra.
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        ans[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }
    return ans;
}

int main() {
    auto r1 = productExceptSelf({1,2,3,4});
    cout << "ProdExcept 1: "; for (int x : r1) cout << x << ' '; cout << '\n';
    auto r2 = productExceptSelf({-1,1,0,-3,3});
    cout << "ProdExcept 2: "; for (int x : r2) cout << x << ' '; cout << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) (output excluded)
*/
