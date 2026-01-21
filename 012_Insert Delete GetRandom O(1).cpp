/*
Insert Delete GetRandom O(1)

Design a data structure that supports insert(val), remove(val), and getRandom() in average O(1) time.

Strategy: Maintain a vector of values and an unordered_map from value -> index in vector. On remove, swap with last and pop_back.
*/

#include <unordered_map>
#include <vector>
#include <random>
#include <iostream>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> idx;
    vector<int> vals;
    mt19937 rng{random_device{}()};
public:
    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) return false;
        int i = it->second;
        int last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(it);
        return true;
    }
    int getRandom() {
        uniform_int_distribution<int> dist(0, (int)vals.size()-1);
        return vals[dist(rng)];
    }
};

int main() {
    RandomizedSet rs;
    cout << rs.insert(1) << '\n'; // true
    cout << rs.remove(2) << '\n'; // false
    cout << rs.insert(2) << '\n'; // true
    cout << rs.getRandom() << '\n'; // 1 or 2
    cout << rs.remove(1) << '\n'; // true
    cout << rs.insert(2) << '\n'; // false (already present)
    cout << rs.getRandom() << '\n'; // 2
    return 0;
}

/*
Time Complexity: O(1) average per operation
Space Complexity: O(n)
*/
