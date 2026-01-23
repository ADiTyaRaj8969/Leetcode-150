"""
Text Justification

Format text to be fully justified given max width.
"""

from typing import List

def full_justify(words: List[str], maxWidth: int) -> List[str]:
    res = []
    i = 0
    n = len(words)
    while i < n:
        j = i
        lineLen = 0
        while j < n and lineLen + len(words[j]) + (j - i) <= maxWidth:
            lineLen += len(words[j])
            j += 1
        gaps = j - i - 1
        if j == n or gaps == 0:
            line = ' '.join(words[i:j])
            line += ' ' * (maxWidth - len(line))
        else:
            totalSpaces = maxWidth - lineLen
            spaceEach = totalSpaces // gaps
            extra = totalSpaces % gaps
            parts = []
            for k in range(i, j):
                parts.append(words[k])
                if k < j - 1:
                    sp = spaceEach + (1 if (k - i) < extra else 0)
                    parts.append(' ' * sp)
            line = ''.join(parts)
        res.append(line)
        i = j
    return res


if __name__ == '__main__':
    w1 = ["This","is","an","example","of","text","justification."]
    out1 = full_justify(w1, 16)
    print('Justify 1:')
    for l in out1: print(f'"{l}"')

    w2 = ["What","must","be","acknowledgment","shall","be"]
    out2 = full_justify(w2, 16)
    print('Justify 2:')
    for l in out2: print(f'"{l}"')

# Time Complexity: O(S) where S is total characters
# Space Complexity: O(S)
