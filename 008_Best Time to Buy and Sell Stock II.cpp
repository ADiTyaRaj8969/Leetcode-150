/*
Best Time to Buy and Sell Stock II

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Find the maximum profit.

Strategy: Sum all positive price differences between consecutive days.
*/

#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
    }
    return profit;
}


int main() {
    cout << "MaxProfitII 1: " << maxProfit({7,1,5,3,6,4}) << '\n';
    cout << "MaxProfitII 2: " << maxProfit({1,2,3,4,5}) << '\n';
    cout << "MaxProfitII 3: " << maxProfit({7,6,4,3,1}) << '\n';
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
