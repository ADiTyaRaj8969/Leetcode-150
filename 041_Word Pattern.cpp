/*
Word Pattern

Given a pattern and a string s, check if s follows the same pattern.
Example: pattern = "abba", s = "dog cat cat dog" -> true
*/

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    istringstream iss(s);
    vector<string> words;
    string w;
    while (iss >> w) words.push_back(w);
    if (pattern.size() != words.size()) return false;
    unordered_map<char,string> p2w;
    unordered_map<string,char> w2p;
    for (int i = 0; i < (int)pattern.size(); ++i) {
        char c = pattern[i];
        const string &word = words[i];
        if (p2w.count(c) && p2w[c] != word) return false;
        if (w2p.count(word) && w2p[word] != c) return false;
        p2w[c] = word; w2p[word] = c;
    }
    return true;
}

int main() {
    cout << "Pattern 1: " << (wordPattern("abba","dog cat cat dog")?"true":"false") << endl;
    cout << "Pattern 2: " << (wordPattern("abba","dog cat cat fish")?"true":"false") << endl;
    cout << "Pattern 3: " << (wordPattern("aaaa","dog cat cat dog")?"true":"false") << endl;
    return 0;
}

// Time Complexity: O(n) where n = number of words
// Space Complexity: O(n)
