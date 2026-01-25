/*
Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence. Must run in O(n) time.
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    
    for (int num : numSet) {
        // Only start counting if num is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
            
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;
            }
            
            longest = max(longest, currentStreak);
        }
    }
    
    return longest;
}

int main() {
    vector<int> n1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1: " << longestConsecutive(n1) << endl; // 4

    vector<int> n2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2: " << longestConsecutive(n2) << endl; // 9

    vector<int> n3 = {};
    cout << "Test 3: " << longestConsecutive(n3) << endl; // 0
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
