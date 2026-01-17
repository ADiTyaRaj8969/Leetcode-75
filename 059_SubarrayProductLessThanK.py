"""
Topic: Sliding Window / Two pointers
Problem: Subarray Product Less Than K
Description: Count contiguous subarrays whose product is less than k.
Time: O(n)
Space: O(1)
"""

from typing import List


def numSubarrayProductLessThanK(nums: List[int], k: int) -> int:
    if k <= 1:
        return 0
    prod = 1
    left = 0
    ans = 0
    for right, val in enumerate(nums):
        prod *= val
        while prod >= k:
            prod //= nums[left]
            left += 1
        ans += right - left + 1
    return ans


if __name__ == '__main__':
    print(numSubarrayProductLessThanK([10,5,2,6], 100))  # 8
    print(numSubarrayProductLessThanK([1,2,3], 0))  # 0
