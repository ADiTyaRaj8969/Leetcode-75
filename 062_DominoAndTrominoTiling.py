"""
Topic: Dynamic Programming
Problem: Domino and Tromino Tiling
Description: Count tilings using DP recurrence mod 1e9+7.
Time: O(n)
Space: O(1)
"""

MOD = 10**9 + 7


def numTilings(n: int) -> int:
    if n == 0:
        return 1
    if n == 1:
        return 1
    # dp[i] = dp[i-1] + dp[i-2] + 2*sum(dp[0..i-3]) can be optimized
    a, b, c = 1, 1, 2  # dp0, dp1, dp2
    if n == 2:
        return 2
    for i in range(3, n+1):
        a, b, c = b, c, (c + b + 2*a) % MOD
    return c


if __name__ == '__main__':
    print(numTilings(3))  # 5
    print(numTilings(1))  # 1
