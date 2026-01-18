"""
Topic: Dynamic Programming
Problem: Edit Distance
Description: Minimum operations (insert/delete/replace) to convert word1 to word2.
Time: O(n*m)
Space: O(min(n,m)) optimized
"""

from typing import List


def minDistance(word1: str, word2: str) -> int:
    if len(word1) < len(word2):
        word1, word2 = word2, word1
    m, n = len(word1), len(word2)
    prev = list(range(n+1))
    for i in range(1, m+1):
        cur = [i] * (n+1)
        for j in range(1, n+1):
            if word1[i-1] == word2[j-1]:
                cur[j] = prev[j-1]
            else:
                cur[j] = 1 + min(prev[j], cur[j-1], prev[j-1])
        prev = cur
    return prev[n]


if __name__ == '__main__':
    print(minDistance("horse", "ros"))  # 3
    print(minDistance("intention", "execution"))  # 5
