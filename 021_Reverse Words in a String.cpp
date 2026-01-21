/*
Reverse Words in a String

Given an input string s, reverse the order of the words.
Words are separated by spaces. Remove leading/trailing spaces and reduce multiple spaces to single between words.

Strategy: Trim, split by spaces, then join words in reverse order. Efficient in-place reverse approach also possible.
*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    vector<string> words;
    string w;
    while (iss >> w) words.push_back(w);
    string res;
    for (int i = (int)words.size() - 1; i >= 0; --i) {
        res += words[i];
        if (i) res += ' ';
    }
    return res;
}

int main() {
    cout << "RevWords 1: '" << reverseWords("the sky is blue") << "'\n";
    cout << "RevWords 2: '" << reverseWords("  hello world  ") << "'\n";
    cout << "RevWords 3: '" << reverseWords("a good   example") << "'\n";
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
