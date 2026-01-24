"""
Valid Anagram

Check if two strings are anagrams of each other.
"""

def is_anagram(s: str, t: str) -> bool:
    if len(s) != len(t): return False
    from collections import Counter
    return Counter(s) == Counter(t)


if __name__ == '__main__':
    print('Anagram 1:', is_anagram('anagram','nagaram'))
    print('Anagram 2:', is_anagram('rat','car'))

# Time Complexity: O(n)
# Space Complexity: O(1) (alphabet constant) or O(n) for general unicode
