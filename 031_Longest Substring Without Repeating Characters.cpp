/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    vector<int> last(256, -1);
    int start = 0, best = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        start = max(start, last[(unsigned char)s[i]] + 1);
        best = max(best, i - start + 1);
        last[(unsigned char)s[i]] = i;
    }
    return best;
}

int main() {
    cout << "Longest 1: " << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << "Longest 2: " << lengthOfLongestSubstring("bbbbb") << endl; // 1
    cout << "Longest 3: " << lengthOfLongestSubstring("pwwkew") << endl; // 3
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (fixed 256-size array)
