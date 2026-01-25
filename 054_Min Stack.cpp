/*
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int,int>> st; // value, current min
public:
    MinStack() {}
    void push(int x) { if (st.empty()) st.push({x,x}); else st.push({x, min(x, st.top().second)}); }
    void pop() { if (!st.empty()) st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "Min 1: " << ms.getMin() << endl; // -3
    ms.pop();
    cout << "Top: " << ms.top() << endl; // 0
    cout << "Min 2: " << ms.getMin() << endl; // -2
    return 0;
}

// Time Complexity: O(1) per op
// Space Complexity: O(n)
