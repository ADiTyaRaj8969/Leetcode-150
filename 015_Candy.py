"""
Candy

Distribute candies to children so that each child has at least one candy and children with higher ratings than neighbors get more.
"""

from typing import List

def candy(ratings: List[int]) -> int:
    n = len(ratings)
    if n == 0: return 0
    candies = [1] * n
    for i in range(1, n):
        if ratings[i] > ratings[i-1]:
            candies[i] = candies[i-1] + 1
    for i in range(n-2, -1, -1):
        if ratings[i] > ratings[i+1]:
            candies[i] = max(candies[i], candies[i+1] + 1)
    return sum(candies)


if __name__ == '__main__':
    print('Candy 1:', candy([1,0,2]))
    print('Candy 2:', candy([1,2,2]))

# Time Complexity: O(n)
# Space Complexity: O(n)
