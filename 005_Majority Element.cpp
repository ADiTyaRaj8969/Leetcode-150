/*
Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
You may assume that the majority element always exists in the array.

Strategy: Boyer-Moore Voting Algorithm (O(n) time, O(1) space).
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int majorityElement(const vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}


int main() {
    vector<int> a1 = {3,2,3};
    cout << "Majority 1: " << majorityElement(a1) << '\n';

    vector<int> a2 = {2,2,1,1,1,2,2};
    cout << "Majority 2: " << majorityElement(a2) << '\n';

    vector<int> a3 = {1};
    cout << "Majority 3: " << majorityElement(a3) << '\n';

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
