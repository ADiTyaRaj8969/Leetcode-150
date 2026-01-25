"""
Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid (correctly opened and closed).
"""

def is_valid(s: str) -> bool:
    pairs = {')':'(', ']':'[', '}':'{'}
    st = []
    for c in s:
        if c in '([{': st.append(c)
        else:
            if not st or st[-1] != pairs.get(c):
                return False
            st.pop()
    return not st


if __name__ == '__main__':
    print('Par 1:', is_valid('()'))
    print('Par 2:', is_valid('()[]{}'))
    print('Par 3:', is_valid('(]'))

# Time Complexity: O(n)
# Space Complexity: O(n)
