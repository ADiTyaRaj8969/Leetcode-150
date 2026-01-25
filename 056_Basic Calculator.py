"""
Basic Calculator

Implement a basic calculator to evaluate a simple expression string containing
non-negative integers, '+', '-', '(', ')', and spaces.
"""

def calculate(s: str) -> int:
    res = 0
    num = 0
    sign = 1
    stack = []
    for c in s:
        if c.isdigit():
            num = num * 10 + int(c)
        elif c == '+':
            res += sign * num
            num = 0
            sign = 1
        elif c == '-':
            res += sign * num
            num = 0
            sign = -1
        elif c == '(':
            stack.append(res)
            stack.append(sign)
            res = 0
            sign = 1
        elif c == ')':
            res += sign * num
            num = 0
            prev_sign = stack.pop()
            prev_res = stack.pop()
            res = prev_res + prev_sign * res
        # ignore spaces
    res += sign * num
    return res


if __name__ == '__main__':
    print('Calc 1:', calculate('1 + 1'))
    print('Calc 2:', calculate(' 2-1 + 2 '))
    print('Calc 3:', calculate('(1+(4+5+2)-3)+(6+8)'))

# Time Complexity: O(n)
# Space Complexity: O(n)
