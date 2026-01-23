/*
Valid Palindrome

Check if a string is a palindrome considering only alphanumeric characters and ignoring cases.

Strategy: Two-pointer scan, skip non-alphanumeric and compare lowercased chars.
*/

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum((unsigned char)s[l])) ++l;
        while (l < r && !isalnum((unsigned char)s[r])) --r;
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
        ++l; --r;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << "IsPal 1: " << isPalindrome("A man, a plan, a canal: Panama") << '\n';
    cout << "IsPal 2: " << isPalindrome("race a car") << '\n';
    cout << "IsPal 3: " << isPalindrome("") << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
