/*
Summary Ranges

Given a sorted unique integer array nums, return the smallest sorted list of ranges
that cover all the numbers in the array exactly.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if (nums.empty()) return result;
    
    int start = nums[0];
    int end = nums[0];
    
    for (int i = 1; i < (int)nums.size(); ++i) {
        if (nums[i] == end + 1) {
            end = nums[i];
        } else {
            if (start == end) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(end));
            }
            start = end = nums[i];
        }
    }
    
    // Add the last range
    if (start == end) {
        result.push_back(to_string(start));
    } else {
        result.push_back(to_string(start) + "->" + to_string(end));
    }
    
    return result;
}

int main() {
    vector<int> n1 = {0, 1, 2, 4, 5, 7};
    auto r1 = summaryRanges(n1);
    cout << "Test 1: ";
    for (auto& s : r1) cout << s << " ";
    cout << endl; // ["0->2","4->5","7"]

    vector<int> n2 = {0, 2, 3, 4, 6, 8, 9};
    auto r2 = summaryRanges(n2);
    cout << "Test 2: ";
    for (auto& s : r2) cout << s << " ";
    cout << endl; // ["0","2->4","6","8->9"]
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) excluding output
