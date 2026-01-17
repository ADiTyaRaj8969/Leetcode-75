"""
Topic: Heap / Selection
Problem: Kth Largest Element in an Array
Description: Return the k-th largest element.
Time: O(n log k) using heap
Space: O(k)
"""

import heapq
from typing import List


def findKthLargest(nums: List[int], k: int) -> int:
    # maintain min-heap of size k
    h = nums[:k]
    heapq.heapify(h)
    for x in nums[k:]:
        if x > h[0]:
            heapq.heapreplace(h, x)
    return h[0]


if __name__ == '__main__':
    print(findKthLargest([3,2,1,5,6,4], 2))  # 5
    print(findKthLargest([3,2,3,1,2,4,5,5,6], 4))  # 4
