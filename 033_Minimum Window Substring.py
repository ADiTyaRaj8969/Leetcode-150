"""
Minimum Window Substring

Given strings s and t, return the minimum window in s which will contain all the characters in t.
"""

from collections import Counter

def min_window(s: str, t: str) -> str:
    if not s or not t: return ""
    need = Counter(t)
    missing = len(t)
    left = 0
    start = 0
    min_len = float('inf')
    for right, ch in enumerate(s):
        if need[ch] > 0:
            missing -= 1
        need[ch] -= 1
        while missing == 0:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                start = left
            need[s[left]] += 1
            if need[s[left]] > 0:
                missing += 1
            left += 1
    return "" if min_len == float('inf') else s[start:start+min_len]


if __name__ == '__main__':
    print('Window 1:', min_window('ADOBECODEBANC', 'ABC'))
    print('Window 2:', min_window('a', 'a'))
    print('Window 3:', min_window('a', 'aa'))

# Time Complexity: O(n + m)
# Space Complexity: O(charset)
