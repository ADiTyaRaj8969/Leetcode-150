/*
Simplify Path

Simplify an absolute Unix-style path.
*/

#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    vector<string> st;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {
        if (token.empty() || token == ".") continue;
        if (token == "..") {
            if (!st.empty()) st.pop_back();
        } else st.push_back(token);
    }
    if (st.empty()) return "/";
    string res;
    for (auto &p: st) res += "/" + p;
    return res;
}

int main() {
    cout << "Simplify 1: " << simplifyPath("/home/") << endl; // /home
    cout << "Simplify 2: " << simplifyPath("/a/./b/../../c/") << endl; // /c
    cout << "Simplify 3: " << simplifyPath("/../") << endl; // /
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
