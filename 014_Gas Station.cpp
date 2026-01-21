/*
Gas Station

Given two arrays gas and cost, return the starting gas station index if you can travel around the circuit once, otherwise -1.

Strategy: If total gas >= total cost, there is a solution. Greedy: accumulate tank and reset start when tank < 0.
*/

#include <vector>
#include <iostream>
using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int n = gas.size();
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int main() {
    cout << "GasStation 1: " << canCompleteCircuit({1,2,3,4,5}, {3,4,5,1,2}) << '\n'; // 3
    cout << "GasStation 2: " << canCompleteCircuit({2,3,4}, {3,4,3}) << '\n'; // -1
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
