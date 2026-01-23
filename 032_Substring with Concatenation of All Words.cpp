/*
Substring with Concatenation of All Words

Given a string s and an array of words of equal length, return all starting indices of substrings
that are a concatenation of each word exactly once and without any intervening characters.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (words.empty() || s.empty()) return res;
    int wordLen = words[0].size(), wordCount = words.size(), total = wordLen * wordCount;
    if ((int)s.size() < total) return res;
    unordered_map<string,int> need;
    for (auto &w: words) need[w]++;

    for (int i = 0; i < wordLen; ++i) {
        int left = i, count = 0;
        unordered_map<string,int> window;
        for (int j = i; j + wordLen <= (int)s.size(); j += wordLen) {
            string w = s.substr(j, wordLen);
            if (need.count(w)) {
                window[w]++;
                ++count;
                while (window[w] > need[w]) {
                    string leftw = s.substr(left, wordLen);
                    window[leftw]--;
                    --count;
                    left += wordLen;
                }
                if (count == wordCount) res.push_back(left);
            } else {
                window.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return res;
}

int main() {
    string s1 = "barfoothefoobarman";
    vector<string> w1 = {"foo","bar"};
    auto r1 = findSubstring(s1, w1);
    cout << "Concat 1:";
    for (int x: r1) cout << ' ' << x;
    cout << endl; // 0 9

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> w2 = {"word","good","best","word"};
    auto r2 = findSubstring(s2, w2);
    cout << "Concat 2:";
    for (int x: r2) cout << ' ' << x;
    cout << endl; // empty

    return 0;
}

// Time Complexity: O(n * wordLen)
// Space Complexity: O(number of distinct words)
