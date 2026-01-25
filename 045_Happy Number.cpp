/*
Happy Number

Determine if a number is happy: repeatedly replace number with sum of squares of digits;
if it becomes 1 it's happy; detect cycles otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

int next_num(int n) {
    int s = 0;
    while (n > 0) {
        int d = n % 10;
        s += d*d;
        n /= 10;
    }
    return s;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = next_num(slow);
        fast = next_num(next_num(fast));
    } while (slow != fast);
    return slow == 1;
}

int main() {
    cout << "Happy 1: " << (isHappy(19)?"true":"false") << endl; // true
    cout << "Happy 2: " << (isHappy(2)?"true":"false") << endl; // false
    return 0;
}

// Time Complexity: O(log n) per iteration, overall amortized O(1) for limited states
// Space Complexity: O(1)
