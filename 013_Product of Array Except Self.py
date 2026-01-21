"""
Product of Array Except Self

Return an array answer where answer[i] is the product of all elements except nums[i] without using division.
"""

from typing import List

def product_except_self(nums: List[int]) -> List[int]:
    n = len(nums)
    ans = [1] * n
    prefix = 1
    for i in range(n):
        ans[i] = prefix
        prefix *= nums[i]
    suffix = 1
    for i in range(n-1, -1, -1):
        ans[i] *= suffix
        suffix *= nums[i]
    return ans


if __name__ == '__main__':
    print('ProdExcept 1:', product_except_self([1,2,3,4]))
    print('ProdExcept 2:', product_except_self([-1,1,0,-3,3]))

# Time Complexity: O(n)
# Space Complexity: O(1) (output excluded)
