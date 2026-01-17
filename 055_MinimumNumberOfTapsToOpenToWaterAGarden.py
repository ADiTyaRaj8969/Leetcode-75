"""
Topic: Greedy / Interval Cover
Problem: Minimum Number of Taps to Open to Water a Garden
Description: Transform taps to intervals and use greedy jump (like jump game II).
Time: O(n)
Space: O(n)
"""

from typing import List


def minTaps(n: int, ranges: List[int]) -> int:
    max_reach = [0] * (n + 1)
    for i, r in enumerate(ranges):
        left = max(0, i - r)
        right = min(n, i + r)
        max_reach[left] = max(max_reach[left], right)

    taps = 0
    curr_end = 0
    next_end = 0
    i = 0
    while curr_end < n:
        while i <= curr_end:
            next_end = max(next_end, max_reach[i])
            i += 1
        if next_end == curr_end:
            return -1
        taps += 1
        curr_end = next_end
    return taps


if __name__ == '__main__':
    print(minTaps(5, [3,4,1,1,0,0]))  # 1
    print(minTaps(3, [0,0,0,0]))  # -1
