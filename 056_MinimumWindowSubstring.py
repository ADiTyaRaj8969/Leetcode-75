"""
Topic: Sliding Window / Hashmap
Problem: Minimum Window Substring
Description: Find smallest substring containing all chars of t in s.
Time: O(n)
Space: O(1) (alphabet) or O(|T|)
"""

from collections import Counter


def minWindow(s: str, t: str) -> str:
    if not t or not s:
        return ""
    need = Counter(t)
    missing = len(t)
    left = 0
    best = (float('inf'), None, None)
    for right, ch in enumerate(s):
        if need[ch] > 0:
            missing -= 1
        need[ch] -= 1
        while missing == 0:
            if right - left + 1 < best[0]:
                best = (right-left+1, left, right)
            need[s[left]] += 1
            if need[s[left]] > 0:
                missing += 1
            left += 1
    return "" if best[1] is None else s[best[1]:best[2]+1]


if __name__ == '__main__':
    print(minWindow("ADOBECODEBANC", "ABC"))  # BANC
    print(minWindow("a", "a"))  # a
