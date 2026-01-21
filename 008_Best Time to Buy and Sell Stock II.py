"""
Best Time to Buy and Sell Stock II

You may complete as many transactions as you like. Find the maximum profit.

Strategy: Greedy — add every positive consecutive difference.
"""

from typing import List

def max_profit(prices: List[int]) -> int:
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i-1]:
            profit += prices[i] - prices[i-1]
    return profit


if __name__ == '__main__':
    print('MaxProfitII 1:', max_profit([7,1,5,3,6,4]))
    print('MaxProfitII 2:', max_profit([1,2,3,4,5]))
    print('MaxProfitII 3:', max_profit([7,6,4,3,1]))

# Time Complexity: O(n)
# Space Complexity: O(1)
