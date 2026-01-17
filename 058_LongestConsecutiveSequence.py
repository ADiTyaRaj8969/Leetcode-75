"""
Topic: Hashset
Problem: Longest Consecutive Sequence
Description: Find the length of the longest consecutive elements sequence.
Time: O(n)
Space: O(n)
"""

from typing import List


def longestConsecutive(nums: List[int]) -> int:
    s = set(nums)
    best = 0
    for x in s:
        if x-1 not in s:
            length = 1
            while x+length in s:
                length += 1
            best = max(best, length)
    return best


if __name__ == '__main__':
    print(longestConsecutive([100,4,200,1,3,2]))  # 4
    print(longestConsecutive([]))  # 0
