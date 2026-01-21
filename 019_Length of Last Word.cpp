/*
Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

Strategy: Trim trailing spaces and find last token length in one pass from end.
*/

#include <string>
#include <iostream>
using namespace std;

int lengthOfLastWord(const string& s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') --i;
    int len = 0;
    while (i >= 0 && s[i] != ' ') { ++len; --i; }
    return len;
}

int main() {
    cout << "LenLast 1: " << lengthOfLastWord("Hello World") << '\n';
    cout << "LenLast 2: " << lengthOfLastWord("   fly me   to   the moon  ") << '\n';
    cout << "LenLast 3: " << lengthOfLastWord("luffy is still joyboy") << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
