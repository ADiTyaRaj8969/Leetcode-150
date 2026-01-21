/*
Candy

Distribute candies to children standing in a line given ratings. Each child must have at least one candy and children with a higher rating than an immediate neighbor must get more candies.

Strategy: Two-pass greedy. Left-to-right ensure right heavier than left; right-to-left enforce left heavier than right using max.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int candy(const vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;
    vector<int> candies(n,1);
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
    for (int i = n-2; i >= 0; --i)
        if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
    int sum = 0; for (int x : candies) sum += x;
    return sum;
}

int main() {
    cout << "Candy 1: " << candy({1,0,2}) << '\n'; // 5
    cout << "Candy 2: " << candy({1,2,2}) << '\n'; // 4
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
