/*
Find the Index of the First Occurrence in a String

Return the index of the first occurrence of needle in haystack, or -1 if not found.

Strategy: Use std::string::find (or implement KMP for linear worst-case). We'll use find for simplicity.
*/

#include <string>
#include <iostream>
using namespace std;

int strStr(const string& haystack, const string& needle) {
    if (needle.empty()) return 0;
    size_t pos = haystack.find(needle);
    if (pos == string::npos) return -1;
    return (int)pos;
}

int main() {
    cout << "StrStr 1: " << strStr("hello","ll") << '\n';
    cout << "StrStr 2: " << strStr("aaaaa","bba") << '\n';
    cout << "StrStr 3: " << strStr("","") << '\n';
    return 0;
}

/*
Time Complexity: O(n*m) in worst-case for naive, but std::string::find is optimized; KMP gives O(n+m)
Space Complexity: O(1)
*/
