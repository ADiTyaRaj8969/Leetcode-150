"""
LRU Cache

Design a Least Recently Used (LRU) cache supporting get and put operations.
"""

from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.od = OrderedDict()
    def get(self, key: int) -> int:
        if key not in self.od:
            return -1
        val = self.od.pop(key)
        self.od[key] = val
        return val
    def put(self, key: int, value: int) -> None:
        if key in self.od:
            self.od.pop(key)
        elif len(self.od) == self.cap:
            self.od.popitem(last=False)
        self.od[key] = value


if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1,1); cache.put(2,2)
    print('LRU get 1:', cache.get(1))
    cache.put(3,3)
    print('LRU get 2:', cache.get(2))
    cache.put(4,4)
    print('LRU get 1:', cache.get(1))
    print('LRU get 3:', cache.get(3))
    print('LRU get 4:', cache.get(4))

# Time Complexity: O(1) per op (amortized)
# Space Complexity: O(capacity)
