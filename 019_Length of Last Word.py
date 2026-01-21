"""
Length of Last Word

Return the length of the last word in a string.
"""

def length_of_last_word(s: str) -> int:
    i = len(s) - 1
    while i >= 0 and s[i] == ' ': i -= 1
    length = 0
    while i >= 0 and s[i] != ' ':
        length += 1
        i -= 1
    return length


if __name__ == '__main__':
    print('LenLast 1:', length_of_last_word('Hello World'))
    print('LenLast 2:', length_of_last_word('   fly me   to   the moon  '))
    print('LenLast 3:', length_of_last_word('luffy is still joyboy'))

# Time Complexity: O(n)
# Space Complexity: O(1)
