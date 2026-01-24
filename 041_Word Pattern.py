"""
Word Pattern

Given a pattern and a string s, check if s follows the same pattern.
"""

def word_pattern(pattern: str, s: str) -> bool:
    words = s.split()
    if len(pattern) != len(words): return False
    p2w, w2p = {}, {}
    for c, w in zip(pattern, words):
        if c in p2w and p2w[c] != w: return False
        if w in w2p and w2p[w] != c: return False
        p2w[c] = w; w2p[w] = c
    return True


if __name__ == '__main__':
    print('Pattern 1:', word_pattern('abba','dog cat cat dog'))
    print('Pattern 2:', word_pattern('abba','dog cat cat fish'))
    print('Pattern 3:', word_pattern('aaaa','dog cat cat dog'))

# Time Complexity: O(n)
# Space Complexity: O(n)
