"""
Reverse Words in a String

Reverse the order of words in a string. Remove extra spaces.
"""

def reverse_words(s: str) -> str:
    parts = s.split()
    return ' '.join(reversed(parts))


if __name__ == '__main__':
    print("RevWords 1:", reverse_words("the sky is blue"))
    print("RevWords 2:", reverse_words("  hello world  "))
    print("RevWords 3:", reverse_words("a good   example"))

# Time Complexity: O(n)
# Space Complexity: O(n)
