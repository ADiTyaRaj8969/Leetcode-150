/*
Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in-place and return the new length.
The relative order of the elements may be changed. Do not allocate extra space for another array; do this by modifying the input array in-place with O(1) extra memory.

Strategy: Two-pointer approach: overwrite unwanted values.
*/

#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // position to place next non-val
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}


static void printVec(const vector<int>& v, int k) {
    for (int i = 0; i < k; ++i) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    // Test 1
    vector<int> t1 = {3,2,2,3};
    int k1 = removeElement(t1, 3);
    cout << "New len 1: " << k1 << ", arr: "; printVec(t1, k1);

    // Test 2
    vector<int> t2 = {0,1,2,2,3,0,4,2};
    int k2 = removeElement(t2, 2);
    cout << "New len 2: " << k2 << ", arr: "; printVec(t2, k2);

    // Test 3
    vector<int> t3 = {1,1,1};
    int k3 = removeElement(t3, 1);
    cout << "New len 3: " << k3 << ", arr: "; printVec(t3, k3);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
