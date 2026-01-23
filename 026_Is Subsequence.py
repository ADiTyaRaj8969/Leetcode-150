"""
Is Subsequence

Check if s is a subsequence of t.
"""

def is_subsequence(s: str, t: str) -> bool:
    it = iter(t)
    for ch in s:
        found = False
        for x in it:
            if x == ch:
                found = True
                break
        if not found:
            return False
    return True


if __name__ == '__main__':
    print('IsSub 1:', is_subsequence('abc', 'ahbgdc'))
    print('IsSub 2:', is_subsequence('axc', 'ahbgdc'))

# Time Complexity: O(n)
# Space Complexity: O(1)
