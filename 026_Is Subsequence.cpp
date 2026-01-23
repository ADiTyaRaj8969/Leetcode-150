/*
Is Subsequence

Check if s is a subsequence of t.

Strategy: Two-pointer scan over t to match s.
*/

#include <string>
#include <iostream>
using namespace std;

bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == (int)s.size();
}

int main() {
    cout << boolalpha;
    cout << "IsSub 1: " << isSubsequence("abc", "ahbgdc") << '\n';
    cout << "IsSub 2: " << isSubsequence("axc", "ahbgdc") << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
