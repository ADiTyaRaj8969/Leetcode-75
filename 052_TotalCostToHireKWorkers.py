"""
Topic: Heap / Two pointers
Problem: Total Cost to Hire K Workers (LeetCode 2462)
Description: Choose k workers with minimal total cost from candidates taken from both ends.
Time: O(k log n)
Space: O(n)
"""

import heapq
from typing import List


def totalCost(costs: List[int], k: int, candidates: int) -> int:
    n = len(costs)
    left_heap = []
    right_heap = []
    i, j = 0, n-1
    # initially push up to candidates from both ends
    for _ in range(candidates):
        if i <= j:
            heapq.heappush(left_heap, (costs[i], i))
            i += 1
    for _ in range(candidates):
        if i <= j:
            heapq.heappush(right_heap, (costs[j], j))
            j -= 1

    total = 0
    for _ in range(k):
        # choose smaller head, tie-break by index (left preferred)
        left_val = left_heap[0] if left_heap else (float('inf'), None)
        right_val = right_heap[0] if right_heap else (float('inf'), None)
        if left_val <= right_val:
            v, idx = heapq.heappop(left_heap)
            total += v
            if i <= j:
                heapq.heappush(left_heap, (costs[i], i)); i += 1
        else:
            v, idx = heapq.heappop(right_heap)
            total += v
            if i <= j:
                heapq.heappush(right_heap, (costs[j], j)); j -= 1
    return total


if __name__ == '__main__':
    print(totalCost([17,12,10,2,7,2,11,20,8], 3, 4))  # expected 11 (2+7+2)
    print(totalCost([1,2,4,1], 3, 3))  # expected 4
