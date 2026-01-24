"""
Group Anagrams

Group an array of strings into lists of anagrams.
"""

from typing import List
from collections import defaultdict

def group_anagrams(strs: List[str]) -> List[List[str]]:
    mp = defaultdict(list)
    for s in strs:
        key = ''.join(sorted(s))
        mp[key].append(s)
    return list(mp.values())


if __name__ == '__main__':
    print('Groups:', group_anagrams(["eat","tea","tan","ate","nat","bat"]))

# Time Complexity: O(n * k log k)
# Space Complexity: O(n*k)
