"""
Gas Station

Return starting gas station index to complete circuit, or -1 if impossible.
"""

from typing import List

def can_complete_circuit(gas: List[int], cost: List[int]) -> int:
    total = tank = start = 0
    for i in range(len(gas)):
        diff = gas[i] - cost[i]
        total += diff
        tank += diff
        if tank < 0:
            start = i + 1
            tank = 0
    return start if total >= 0 else -1


if __name__ == '__main__':
    print('GasStation 1:', can_complete_circuit([1,2,3,4,5], [3,4,5,1,2]))
    print('GasStation 2:', can_complete_circuit([2,3,4], [3,4,3]))

# Time Complexity: O(n)
# Space Complexity: O(1)
