"""
Topic: Bit Manipulation
Problem: Single Number
Description: Find the element that appears once when others appear twice.
Time: O(n)
Space: O(1)
"""

from typing import List


def singleNumber(nums: List[int]) -> int:
    res = 0
    for x in nums:
        res ^= x
    return res


if __name__ == '__main__':
    print(singleNumber([2,2,1]))  # 1
    print(singleNumber([4,1,2,1,2]))  # 4
