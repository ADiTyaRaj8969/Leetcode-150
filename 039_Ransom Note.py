"""
Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed
from the letters in magazine. Each letter in magazine can only be used once.
"""

def can_construct(ransom_note: str, magazine: str) -> bool:
    from collections import Counter
    need = Counter(ransom_note)
    avail = Counter(magazine)
    for k, v in need.items():
        if avail[k] < v: return False
    return True


if __name__ == '__main__':
    print('Ransom 1:', can_construct('a', 'b'))
    print('Ransom 2:', can_construct('aa', 'ab'))
    print('Ransom 3:', can_construct('aa', 'aab'))

# Time Complexity: O(n + m)
# Space Complexity: O(1) (alphabet constant)
