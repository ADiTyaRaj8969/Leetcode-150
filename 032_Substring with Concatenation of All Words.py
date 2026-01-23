"""
Substring with Concatenation of All Words

Given a string s and an array of words of equal length, return all starting indices
of substrings that are a concatenation of each word exactly once and without intervening chars.
"""

from typing import List

def find_substring(s: str, words: List[str]) -> List[int]:
    if not s or not words: return []
    word_len = len(words[0])
    word_count = len(words)
    total = word_len * word_count
    if len(s) < total: return []
    from collections import Counter
    need = Counter(words)
    res = []

    for i in range(word_len):
        left = i
        window = Counter()
        count = 0
        for j in range(i, len(s) - word_len + 1, word_len):
            w = s[j:j+word_len]
            if w in need:
                window[w] += 1
                count += 1
                while window[w] > need[w]:
                    left_w = s[left:left+word_len]
                    window[left_w] -= 1
                    left += word_len
                    count -= 1
                if count == word_count:
                    res.append(left)
            else:
                window.clear()
                count = 0
                left = j + word_len
    return res


if __name__ == '__main__':
    print('Concat 1:', find_substring('barfoothefoobarman', ['foo','bar']))
    print('Concat 2:', find_substring('wordgoodgoodgoodbestword', ['word','good','best','word']))

# Time Complexity: O(n * word_len)
# Space Complexity: O(number of distinct words)
