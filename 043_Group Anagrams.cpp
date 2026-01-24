/*
Group Anagrams

Group an array of strings into lists of anagrams.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto &s: strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto &p: mp) res.push_back(p.second);
    return res;
}

int main() {
    vector<string> s1 = {"eat","tea","tan","ate","nat","bat"};
    auto r1 = groupAnagrams(s1);
    cout << "Groups:" << endl;
    for (auto &g: r1) {
        for (auto &w: g) cout << w << ' ';
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n * k log k)
// Space Complexity: O(n*k)
