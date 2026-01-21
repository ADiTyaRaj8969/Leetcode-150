/*
Rotate Array

Rotate an array to the right by k steps, where k is non-negative.

Strategy: Use three reverses: reverse whole array, reverse first k, reverse remaining n-k.
Works in-place with O(1) extra space.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k %= n;
    if (k == 0) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}


static void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    vector<int> a1 = {1,2,3,4,5,6,7};
    rotate(a1, 3);
    cout << "Rotated 1: "; printVec(a1);

    vector<int> a2 = {-1,-100,3,99};
    rotate(a2, 2);
    cout << "Rotated 2: "; printVec(a2);

    vector<int> a3 = {1,2};
    rotate(a3, 0);
    cout << "Rotated 3: "; printVec(a3);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
