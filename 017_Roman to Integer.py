"""
Roman to Integer

Convert Roman numeral to integer.
"""

def roman_to_int(s: str) -> int:
    m = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
    res = 0
    for i, ch in enumerate(s):
        val = m[ch]
        if i + 1 < len(s) and val < m[s[i+1]]:
            res -= val
        else:
            res += val
    return res


if __name__ == '__main__':
    print('Roman 1:', roman_to_int('III'))
    print('Roman 2:', roman_to_int('LVIII'))
    print('Roman 3:', roman_to_int('MCMXCIV'))

# Time Complexity: O(n)
# Space Complexity: O(1)
