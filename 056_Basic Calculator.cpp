/*
Basic Calculator

Implement a basic calculator to evaluate a simple expression string containing
non-negative integers, '+', '-', '(', ')', and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

int calculate(const string &s) {
    int n = s.size();
    int sign = 1; // current sign
    int res = 0;
    int num = 0;
    stack<int> st; // store previous res and sign pairs by pushing res then sign
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            res += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            res += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            // push current result and sign
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            int prevSign = st.top(); st.pop();
            int prevRes = st.top(); st.pop();
            res = prevRes + prevSign * res;
        }
    }
    res += sign * num;
    return res;
}

int main() {
    cout << "Calc 1: " << calculate("1 + 1") << endl; // 2
    cout << "Calc 2: " << calculate(" 2-1 + 2 ") << endl; // 3
    cout << "Calc 3: " << calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 23
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) for stack (parentheses depth)
