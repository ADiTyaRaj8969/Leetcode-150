"""
Best Time to Buy and Sell Stock

Given an array prices where prices[i] is the price of a given stock on the ith day, find the maximum profit by choosing one day to buy and a later day to sell.

Strategy: Track minimum price and update max profit.
"""

from typing import List

def max_profit(prices: List[int]) -> int:
    if not prices:
        return 0
    min_price = prices[0]
    max_prof = 0
    for p in prices[1:]:
        if p < min_price:
            min_price = p
        else:
            max_prof = max(max_prof, p - min_price)
    return max_prof


if __name__ == '__main__':
    print('MaxProfit 1:', max_profit([7,1,5,3,6,4]))
    print('MaxProfit 2:', max_profit([7,6,4,3,1]))
    print('MaxProfit 3:', max_profit([1,2]))

# Time Complexity: O(n)
# Space Complexity: O(1)
