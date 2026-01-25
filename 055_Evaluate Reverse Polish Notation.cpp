/*
Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Operators are +, -, *, /. Division truncates toward zero.
*/

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<long long> st;
    for (auto &tok: tokens) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (tok == "+") st.push(a + b);
            else if (tok == "-") st.push(a - b);
            else if (tok == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoll(tok));
        }
    }
    return (int)st.top();
}

int main() {
    vector<string> t1 = {"2","1","+","3","*"};
    cout << "RPN 1: " << evalRPN(t1) << endl; // 9
    vector<string> t2 = {"4","13","5","/","+"};
    cout << "RPN 2: " << evalRPN(t2) << endl; // 6
    vector<string> t3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "RPN 3: " << evalRPN(t3) << endl; // 22
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
