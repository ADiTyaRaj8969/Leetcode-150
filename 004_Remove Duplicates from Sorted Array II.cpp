/*
Remove Duplicates from Sorted Array II

Given a sorted array nums, remove the duplicates in-place such that duplicates are allowed at most twice.
Return the new length after removal.

Strategy: Two-pointer; allow up to two copies by comparing with nums[k-2].
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;
    int k = 2;
    for (int i = 2; i < n; ++i) {
        if (nums[i] != nums[k-2]) nums[k++] = nums[i];
    }
    return k;
}


static void printVec(const vector<int>& v, int k) {
    for (int i = 0; i < k; ++i) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    vector<int> a1 = {1,1,1,2,2,3};
    int k1 = removeDuplicates(a1);
    cout << "New len 1: " << k1 << ", arr: "; printVec(a1, k1);

    vector<int> a2 = {0,0,0,0,1,1,1};
    int k2 = removeDuplicates(a2);
    cout << "New len 2: " << k2 << ", arr: "; printVec(a2, k2);

    vector<int> a3 = {1,2};
    int k3 = removeDuplicates(a3);
    cout << "New len 3: " << k3 << ", arr: "; printVec(a3, k3);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
