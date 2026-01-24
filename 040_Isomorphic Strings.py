"""
Isomorphic Strings

Given two strings s and t, determine if they are isomorphic. Characters must map one-to-one.
"""

def is_isomorphic(s: str, t: str) -> bool:
    if len(s) != len(t): return False
    m1, m2 = {}, {}
    for i, ch in enumerate(s):
        if ch in m1 and m1[ch] != t[i]: return False
        if t[i] in m2 and m2[t[i]] != ch: return False
        m1[ch] = t[i]
        m2[t[i]] = ch
    return True


if __name__ == '__main__':
    print('Iso 1:', is_isomorphic('egg','add'))
    print('Iso 2:', is_isomorphic('foo','bar'))
    print('Iso 3:', is_isomorphic('paper','title'))

# Time Complexity: O(n)
# Space Complexity: O(min(n, charset))
