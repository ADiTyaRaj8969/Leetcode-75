"""
Topic: Dynamic Programming / Bit Tricks
Problem: Counting Bits
Description: For each i in [0..n], count number of 1 bits.
Time: O(n)
Space: O(n)
"""

from typing import List


def countBits(n: int) -> List[int]:
    res = [0] * (n + 1)
    for i in range(1, n+1):
        res[i] = res[i & (i-1)] + 1
    return res


if __name__ == '__main__':
    print(countBits(2))  # [0,1,1]
    print(countBits(5))  # [0,1,1,2,1,2]
