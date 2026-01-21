/*
Integer to Roman

Convert an integer to its Roman numeral representation.

Strategy: Greedy use value-symbol pairs from largest to smallest.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string intToRoman(int num) {
    vector<pair<int,string>> vals = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
    };
    string res;
    for (auto &p : vals) {
        while (num >= p.first) {
            res += p.second;
            num -= p.first;
        }
        if (num == 0) break;
    }
    return res;
}

int main() {
    cout << "IntToRoman 1: " << intToRoman(3) << '\n';
    cout << "IntToRoman 2: " << intToRoman(58) << '\n';
    cout << "IntToRoman 3: " << intToRoman(1994) << '\n';
    return 0;
}

/*
Time Complexity: O(1) (bounded by constant number of roman tokens)
Space Complexity: O(1)
*/
