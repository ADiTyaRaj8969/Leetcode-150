/*
Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid (correctly opened and closed).
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    unordered_map<char,char> m = {{')','('},{']','['},{'}','{'}};
    vector<char> st;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{') st.push_back(c);
        else {
            if (st.empty() || st.back() != m[c]) return false;
            st.pop_back();
        }
    }
    return st.empty();
}

int main() {
    cout << "Par 1: " << (isValid("()")?"true":"false") << endl;
    cout << "Par 2: " << (isValid("()[]{}")=="true"?"true":"false") << endl; // true
    cout << "Par 3: " << (isValid("(]")?"true":"false") << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
