"""
Topic: Dynamic Programming / Combinatorics
Problem: Unique Paths
Description: Number of ways to reach bottom-right in m x n grid.
Time: O(min(m,n)) using combinatorics
Space: O(1)
"""

from math import comb
from typing import List


def uniquePaths(m: int, n: int) -> int:
    # To move (m-1) down and (n-1) right: total moves = m+n-2, choose m-1
    return comb(m + n - 2, m - 1)


if __name__ == '__main__':
    print(uniquePaths(3, 7))  # 28
    print(uniquePaths(3, 2))  # 3
