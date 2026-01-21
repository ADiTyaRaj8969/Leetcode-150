/*
Best Time to Buy and Sell Stock

Given an array prices where prices[i] is the price of a given stock on the ith day, find the maximum profit by choosing a single day to buy and a later day to sell.

Strategy: Track minimum price seen so far and compute max profit on the fly.
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;
    int minPrice = prices[0];
    int maxProf = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else maxProf = max(maxProf, prices[i] - minPrice);
    }
    return maxProf;
}


int main() {
    vector<int> p1 = {7,1,5,3,6,4};
    cout << "MaxProfit 1: " << maxProfit(p1) << '\n';

    vector<int> p2 = {7,6,4,3,1};
    cout << "MaxProfit 2: " << maxProfit(p2) << '\n';

    vector<int> p3 = {1,2};
    cout << "MaxProfit 3: " << maxProfit(p3) << '\n';

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
