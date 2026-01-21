/*
Roman to Integer

Convert a Roman numeral string to an integer.

Strategy: Map roman chars to values and add/subtract when smaller precedes larger.
*/

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int romanToInt(const string& s) {
    unordered_map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int val = m[s[i]];
        if (i + 1 < n && val < m[s[i+1]]) res -= val;
        else res += val;
    }
    return res;
}

int main() {
    cout << "Roman 1: " << romanToInt("III") << '\n'; // 3
    cout << "Roman 2: " << romanToInt("LVIII") << '\n'; // 58
    cout << "Roman 3: " << romanToInt("MCMXCIV") << '\n'; // 1994
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
