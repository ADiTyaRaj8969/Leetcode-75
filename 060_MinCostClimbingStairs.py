"""
Topic: Dynamic Programming
Problem: Min Cost Climbing Stairs
Description: Minimum cost to reach the top using DP (either from step i or i+1).
Time: O(n)
Space: O(1)
"""

from typing import List


def minCostClimbingStairs(cost: List[int]) -> int:
    a = 0
    b = 0
    for x in reversed(cost):
        a, b = x + min(a, b), a
    return min(a, b)


if __name__ == '__main__':
    print(minCostClimbingStairs([10,15,20]))  # 15
    print(minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))  # 6
