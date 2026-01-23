/*
Zigzag Conversion

Convert s into zigzag form on numRows rows and then read line by line.

Strategy: Simulate rows and append characters moving down/up between rows.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    if (numRows <= 1 || numRows >= (int)s.size()) return s;
    vector<string> rows(min(numRows, int(s.size())));
    int cur = 0;
    bool down = true;
    for (char c : s) {
        rows[cur] += c;
        if (cur == 0) down = true;
        else if (cur == numRows - 1) down = false;
        cur += down ? 1 : -1;
    }
    string res;
    for (auto &r : rows) res += r;
    return res;
}

int main() {
    cout << "Zigzag 1: " << convert("PAYPALISHIRING", 3) << '\n'; // PAHNAPLSIIGYIR
    cout << "Zigzag 2: " << convert("PAYPALISHIRING", 4) << '\n'; // PINALSIGYAHRPI
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
