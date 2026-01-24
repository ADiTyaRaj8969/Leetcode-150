/*
Minimum Window Substring

Given strings s and t, return the minimum window in s which will contain all the characters in t.
If there is no such window, return the empty string.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    vector<int> need(128,0);
    for (char c: t) need[c]++;
    int required = t.size();
    int l = 0, bestLen = INT_MAX, bestL = 0;
    for (int r = 0; r < (int)s.size(); ++r) {
        if (need[s[r]] > 0) --required;
        --need[s[r]];
        while (required == 0) {
            if (r - l + 1 < bestLen) { bestLen = r - l + 1; bestL = l; }
            ++need[s[l]];
            if (need[s[l]] > 0) ++required;
            ++l;
        }
    }
    return bestLen == INT_MAX ? string("") : s.substr(bestL, bestLen);
}

int main() {
    cout << "Window 1: " << minWindow("ADOBECODEBANC", "ABC") << endl; // BANC
    cout << "Window 2: " << minWindow("a", "a") << endl; // a
    cout << "Window 3: " << minWindow("a", "aa") << endl; // empty
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1) (fixed alphabet array)
