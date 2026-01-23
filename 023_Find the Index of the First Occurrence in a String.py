"""
Find the Index of the First Occurrence in a String

Return index of first occurrence of needle in haystack.
"""

def str_str(haystack: str, needle: str) -> int:
    if needle == "":
        return 0
    return haystack.find(needle)


if __name__ == '__main__':
    print('StrStr 1:', str_str('hello','ll'))
    print('StrStr 2:', str_str('aaaaa','bba'))
    print('StrStr 3:', str_str('',''))

# Time Complexity: O(n*m) worst-case, KMP can do O(n+m)
# Space Complexity: O(1)
