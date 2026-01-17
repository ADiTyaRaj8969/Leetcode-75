"""
Topic: Greedy / Heap
Problem: Maximum Subsequence Score (LeetCode 2542)
Description: Choose k indices to maximize sum(nums1_selected) * min(nums2_selected).
Time: O(n log n)
Space: O(n)
"""

import heapq
from typing import List


def maxScore(nums1: List[int], nums2: List[int], k: int) -> int:
    pairs = sorted(zip(nums2, nums1), reverse=True)  # sort by nums2 desc
    heap = []
    s = 0
    ans = 0
    for b, a in pairs:
        heapq.heappush(heap, a)
        s += a
        if len(heap) > k:
            s -= heapq.heappop(heap)
        if len(heap) == k:
            ans = max(ans, s * b)
    return ans


if __name__ == '__main__':
    print(maxScore([1,3,3,2], [2,1,3,4], 3))  # expected 12
    print(maxScore([4,2,3,1,1], [7,3,5,10,9], 1))  # expected 10
