"""
Insert Delete GetRandom O(1)

Implement a data structure that supports insert, remove and getRandom in average O(1).
"""

import random
from typing import List

class RandomizedSet:
    def __init__(self):
        self.idx = {}
        self.vals = []

    def insert(self, val: int) -> bool:
        if val in self.idx:
            return False
        self.idx[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.idx:
            return False
        i = self.idx[val]
        last = self.vals[-1]
        self.vals[i] = last
        self.idx[last] = i
        self.vals.pop()
        del self.idx[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.vals)


if __name__ == '__main__':
    rs = RandomizedSet()
    print(rs.insert(1))
    print(rs.remove(2))
    print(rs.insert(2))
    print(rs.getRandom())
    print(rs.remove(1))
    print(rs.insert(2))
    print(rs.getRandom())

# Time Complexity: O(1) average per operation
# Space Complexity: O(n)
