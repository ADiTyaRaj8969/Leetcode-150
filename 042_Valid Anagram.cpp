/*
Valid Anagram

Check if two strings are anagrams of each other.
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    array<int,26> cnt{};
    for (int i = 0; i < (int)s.size(); ++i) {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for (int x: cnt) if (x) return false;
    return true;
}

int main() {
    cout << "Anagram 1: " << (isAnagram("anagram","nagaram")?"true":"false") << endl;
    cout << "Anagram 2: " << (isAnagram("rat","car")?"true":"false") << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
