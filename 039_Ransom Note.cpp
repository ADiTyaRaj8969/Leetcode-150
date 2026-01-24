/*
Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed
from the letters in magazine. Each letter in magazine can only be used once.
*/

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> cnt(26,0);
    for (char c: magazine) cnt[c - 'a']++;
    for (char c: ransomNote) {
        if (--cnt[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    cout << "Ransom 1: " << (canConstruct("a","b")?"true":"false") << endl; // false
    cout << "Ransom 2: " << (canConstruct("aa","ab")?"true":"false") << endl; // false
    cout << "Ransom 3: " << (canConstruct("aa","aab")?"true":"false") << endl; // true
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)
