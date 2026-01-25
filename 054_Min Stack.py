"""
Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
"""

class MinStack:
    def __init__(self):
        self.st = []  # (val, current_min)
    def push(self, x: int) -> None:
        if not self.st:
            self.st.append((x,x))
        else:
            self.st.append((x, min(x, self.st[-1][1])))
    def pop(self) -> None:
        self.st.pop()
    def top(self) -> int:
        return self.st[-1][0]
    def getMin(self) -> int:
        return self.st[-1][1]


if __name__ == '__main__':
    ms = MinStack()
    ms.push(-2)
    ms.push(0)
    ms.push(-3)
    print('Min 1:', ms.getMin())
    ms.pop()
    print('Top:', ms.top())
    print('Min 2:', ms.getMin())

# Time Complexity: O(1) per operation
# Space Complexity: O(n)
