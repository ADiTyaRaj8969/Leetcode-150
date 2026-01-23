"""
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.
"""

def length_of_longest_substring(s: str) -> int:
    last = {}
    start = 0
    best = 0
    for i, ch in enumerate(s):
        if ch in last and last[ch] >= start:
            start = last[ch] + 1
        best = max(best, i - start + 1)
        last[ch] = i
    return best


if __name__ == '__main__':
    print('Longest 1:', length_of_longest_substring('abcabcbb'))
    print('Longest 2:', length_of_longest_substring('bbbbb'))
    print('Longest 3:', length_of_longest_substring('pwwkew'))

# Time Complexity: O(n)
# Space Complexity: O(min(n, charset))
