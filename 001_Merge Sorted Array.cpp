/*
Merge Sorted Array

Merge two sorted arrays, nums2 into nums1, as one sorted array.
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Modify nums1 in-place such that it contains the merged sorted array.

Strategy: Merge from the end using three pointers. This avoids extra space.
*/

#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}


static void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    // Test 1
    vector<int> a1 = {1,2,3,0,0,0};
    vector<int> b1 = {2,5,6};
    merge(a1, 3, b1, 3);
    cout << "Merged 1: "; printVec(a1);

    // Test 2
    vector<int> a2 = {1};
    vector<int> b2 = {};
    merge(a2, 1, b2, 0);
    cout << "Merged 2: "; printVec(a2);

    // Test 3
    vector<int> a3 = {0};
    vector<int> b3 = {1};
    merge(a3, 0, b3, 1);
    cout << "Merged 3: "; printVec(a3);

    return 0;
}

/*
Time Complexity: O(m + n)
Space Complexity: O(1)
*/
