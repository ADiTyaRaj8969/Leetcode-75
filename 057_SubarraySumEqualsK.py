"""
Topic: Prefix Sum / Hashmap
Problem: Subarray Sum Equals K
Description: Count subarrays whose sum equals k using prefix-sum hashmap.
Time: O(n)
Space: O(n)
"""

from typing import List


def subarraySum(nums: List[int], k: int) -> int:
    from collections import defaultdict
    count = defaultdict(int)
    count[0] = 1
    s = 0
    ans = 0
    for x in nums:
        s += x
        ans += count.get(s - k, 0)
        count[s] += 1
    return ans


if __name__ == '__main__':
    print(subarraySum([1,1,1], 2))  # 2
    print(subarraySum([1,2,3], 3))  # 2
