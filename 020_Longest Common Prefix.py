"""
Longest Common Prefix

Find the longest common prefix string among an array of strings.
"""

from typing import List

def longest_common_prefix(strs: List[str]) -> str:
    if not strs: return ""
    candidate = min(strs, key=len)
    for s in strs:
        i = 0
        while i < len(candidate) and i < len(s) and candidate[i] == s[i]:
            i += 1
        candidate = candidate[:i]
        if not candidate:
            return ""
    return candidate


if __name__ == '__main__':
    print('LCP 1:', longest_common_prefix(['flower','flow','flight']))
    print('LCP 2:', longest_common_prefix(['dog','racecar','car']))
    print('LCP 3:', longest_common_prefix(['interspecies','interstellar','interstate']))

# Time Complexity: O(S) where S is total characters
# Space Complexity: O(1)
