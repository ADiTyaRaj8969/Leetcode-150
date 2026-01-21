/*
H-Index

Given an array of citation counts for a researcher, compute the researcher's h-index.
The h-index is the maximum h such that the researcher has at least h papers with >= h citations.

Strategy: Sort citations descending and find largest h where citations[h-1] >= h. O(n log n).
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int h = 0;
    for (int i = 0; i < (int)citations.size(); ++i) {
        if (citations[i] >= i + 1) h = i + 1;
        else break;
    }
    return h;
}

int main() {
    vector<int> c1 = {3,0,6,1,5};
    cout << "H-Index 1: " << hIndex(c1) << '\n'; // 3

    vector<int> c2 = {10,8,5,4,3};
    cout << "H-Index 2: " << hIndex(c2) << '\n'; // 4

    vector<int> c3 = {0,0,0};
    cout << "H-Index 3: " << hIndex(c3) << '\n'; // 0

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(1) (ignoring input sort space)
*/
