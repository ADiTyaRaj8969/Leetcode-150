"""
Zigzag Conversion

Convert string to zigzag pattern on numRows and read row by row.
"""

def convert(s: str, numRows: int) -> str:
    if numRows <= 1 or numRows >= len(s):
        return s
    rows = [''] * min(numRows, len(s))
    cur = 0
    down = True
    for c in s:
        rows[cur] += c
        if cur == 0:
            down = True
        elif cur == numRows - 1:
            down = False
        cur += 1 if down else -1
    return ''.join(rows)


if __name__ == '__main__':
    print('Zigzag 1:', convert('PAYPALISHIRING', 3))
    print('Zigzag 2:', convert('PAYPALISHIRING', 4))

# Time Complexity: O(n)
# Space Complexity: O(n)
