/*
Two Sum II - Input Array Is Sorted

Given a 1-indexed sorted array of integers, find two numbers such that they add up to a specific target. Return indices (1-indexed).

Strategy: Two-pointer from both ends.
*/

#include <vector>
#include <iostream>
using namespace std;

pair<int,int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target) return {l+1, r+1};
        if (sum < target) ++l; else --r;
    }
    return {-1,-1};
}

int main() {
    vector<int> a1 = {2,7,11,15};
    auto p = twoSum(a1, 9);
    cout << "TwoSumII 1: " << p.first << ',' << p.second << '\n';
    vector<int> a2 = {2,3,4};
    auto p2 = twoSum(a2, 6);
    cout << "TwoSumII 2: " << p2.first << ',' << p2.second << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
