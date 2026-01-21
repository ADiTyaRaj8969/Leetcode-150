/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

Strategy: Horizontal scanning using the shortest string as bound, or vertical checking. Here use shortest-first and check prefixes.
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    auto it = min_element(strs.begin(), strs.end());
    string candidate = *it;
    for (const string& s : strs) {
        int j = 0;
        while (j < (int)candidate.size() && j < (int)s.size() && candidate[j] == s[j]) ++j;
        candidate = candidate.substr(0, j);
        if (candidate.empty()) return "";
    }
    return candidate;
}

int main() {
    vector<string> a1 = {"flower","flow","flight"};
    cout << "LCP 1: " << longestCommonPrefix(a1) << '\n';
    vector<string> a2 = {"dog","racecar","car"};
    cout << "LCP 2: " << longestCommonPrefix(a2) << '\n';
    vector<string> a3 = {"interspecies","interstellar","interstate"};
    cout << "LCP 3: " << longestCommonPrefix(a3) << '\n';
    return 0;
}

/*
Time Complexity: O(S) where S is sum of all characters in input
Space Complexity: O(1)
*/
