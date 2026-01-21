/*
Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and return the new length.
Do not allocate extra space for another array; modify input in-place with O(1) extra memory.

Strategy: Two-pointer where slow pointer stores unique elements.
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
        if (nums[i] != nums[k-1]) nums[k++] = nums[i];
    }
    return k;
}


static void printVec(const vector<int>& v, int k) {
    for (int i = 0; i < k; ++i) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    vector<int> a1 = {1,1,2};
    int k1 = removeDuplicates(a1);
    cout << "New len 1: " << k1 << ", arr: "; printVec(a1, k1);

    vector<int> a2 = {0,0,1,1,1,2,2,3,3,4};
    int k2 = removeDuplicates(a2);
    cout << "New len 2: " << k2 << ", arr: "; printVec(a2, k2);

    vector<int> a3 = {};
    int k3 = removeDuplicates(a3);
    cout << "New len 3: " << k3 << ", arr: "; printVec(a3, k3);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
