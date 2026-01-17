"""
Topic: Heap / Greedy
Problem: Minimum Cost to Connect Sticks
Description: Combine smallest two repeatedly using min-heap.
Time: O(n log n)
Space: O(n)
"""

import heapq
from typing import List


def connectSticks(sticks: List[int]) -> int:
    if not sticks:
        return 0
    heapq.heapify(sticks)
    cost = 0
    while len(sticks) > 1:
        a = heapq.heappop(sticks)
        b = heapq.heappop(sticks)
        cost += a + b
        heapq.heappush(sticks, a + b)
    return cost


if __name__ == '__main__':
    print(connectSticks([2,4,3]))  # 14
    print(connectSticks([1,8,3,5]))  # 30
