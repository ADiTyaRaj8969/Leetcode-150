/*
Isomorphic Strings

Given two strings s and t, determine if they are isomorphic. Characters must map one-to-one.
*/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> m1(256, -1), m2(256, -1);
    for (int i = 0; i < (int)s.size(); ++i) {
        unsigned char a = s[i], b = t[i];
        if (m1[a] != m2[b]) return false;
        m1[a] = m2[b] = i;
    }
    return true;
}

int main() {
    cout << "Iso 1: " << (isIsomorphic("egg","add")?"true":"false") << endl; // true
    cout << "Iso 2: " << (isIsomorphic("foo","bar")?"true":"false") << endl; // false
    cout << "Iso 3: " << (isIsomorphic("paper","title")?"true":"false") << endl; // true
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (fixed alphabet)
