"""
Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Operators are +, -, *, /. Division truncates toward zero.
"""

from typing import List

def eval_rpn(tokens: List[str]) -> int:
    st = []
    for tok in tokens:
        if tok in ('+','-','*','/'):
            b = st.pop(); a = st.pop()
            if tok == '+': st.append(a+b)
            elif tok == '-': st.append(a-b)
            elif tok == '*': st.append(a*b)
            else: st.append(int(a / b))  # truncate toward zero
        else:
            st.append(int(tok))
    return st[-1]


if __name__ == '__main__':
    print('RPN 1:', eval_rpn(["2","1","+","3","*"]))
    print('RPN 2:', eval_rpn(["4","13","5","/","+"]))
    print('RPN 3:', eval_rpn(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))

# Time Complexity: O(n)
# Space Complexity: O(n)
