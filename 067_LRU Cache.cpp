/*
LRU Cache

Design a Least Recently Used (LRU) cache supporting get and put operations.
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> mp; // key -> (value, iterator)
public:
    LRUCache(int capacity): cap(capacity) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        order.erase(it->second.second);
        order.push_front(key);
        it->second.second = order.begin();
        return it->second.first;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            order.erase(it->second.second);
            order.push_front(key);
            it->second = {value, order.begin()};
            return;
        }
        if ((int)mp.size() == cap) {
            int old = order.back(); order.pop_back(); mp.erase(old);
        }
        order.push_front(key);
        mp[key] = {value, order.begin()};
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1,1); cache.put(2,2);
    cout << "LRU get 1: " << cache.get(1) << endl; // 1
    cache.put(3,3);
    cout << "LRU get 2: " << cache.get(2) << endl; // -1
    cache.put(4,4);
    cout << "LRU get 1: " << cache.get(1) << endl; // -1
    cout << "LRU get 3: " << cache.get(3) << endl; // 3
    cout << "LRU get 4: " << cache.get(4) << endl; // 4
    return 0;
}

// Time Complexity: O(1) per operation
// Space Complexity: O(capacity)
