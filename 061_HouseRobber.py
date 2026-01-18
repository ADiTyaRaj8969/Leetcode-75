"""
Topic: Dynamic Programming
Problem: House Robber
Description: Max sum of non-adjacent elements.
Time: O(n)
Space: O(1)
"""

from typing import List


def rob(nums: List[int]) -> int:
    prev = 0
    curr = 0
    for x in nums:
        prev, curr = curr, max(curr, prev + x)
    return curr


if __name__ == '__main__':
    print(rob([1,2,3,1]))  # 4
    print(rob([2,7,9,3,1]))  # 12
