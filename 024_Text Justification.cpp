/*
Text Justification

Format text such that each line has exactly maxWidth characters and is fully (left and right) justified.

Strategy: Greedy pack words into lines then distribute spaces evenly; last line left-justified.
*/

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int n = words.size();
    int i = 0;
    while (i < n) {
        int j = i;
        int lineLen = 0;
        while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
            lineLen += words[j].size();
            ++j;
        }
        int gaps = j - i - 1;
        string line;
        if (j == n || gaps == 0) {
            // left-justify
            for (int k = i; k < j; ++k) {
                line += words[k];
                if ((int)line.size() < maxWidth) line += ' ';
            }
            while ((int)line.size() < maxWidth) line += ' ';
        } else {
            int totalSpaces = maxWidth - lineLen;
            int spaceEach = totalSpaces / gaps;
            int extra = totalSpaces % gaps;
            for (int k = i; k < j; ++k) {
                line += words[k];
                if (k < j - 1) {
                    int sp = spaceEach + ( (k - i) < extra ? 1 : 0 );
                    line += string(sp, ' ');
                }
            }
        }
        res.push_back(line);
        i = j;
    }
    return res;
}

int main() {
    vector<string> w1 = {"This","is","an","example","of","text","justification."};
    auto out1 = fullJustify(w1, 16);
    cout << "Justify 1:\n";
    for (auto &l : out1) cout << '"' << l << '"' << '\n';

    vector<string> w2 = {"What","must","be","acknowledgment","shall","be"};
    auto out2 = fullJustify(w2, 16);
    cout << "Justify 2:\n";
    for (auto &l : out2) cout << '"' << l << '"' << '\n';
    return 0;
}

/*
Time Complexity: O(S) where S is total characters in words
Space Complexity: O(S)
*/
