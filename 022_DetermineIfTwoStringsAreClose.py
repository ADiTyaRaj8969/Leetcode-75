"""
Topic: String / Counting
Determine If Two Strings Are Close: two strings are close if they have same unique chars and same multiset of frequencies
Time Complexity: O(n + m)
Space Complexity: O(1) assuming fixed alphabet
"""

from collections import Counter

def close_strings(word1: str, word2: str) -> bool:
    if set(word1) != set(word2):
        return False
    c1 = sorted(Counter(word1).values())
    c2 = sorted(Counter(word2).values())
    return c1 == c2


if __name__ == '__main__':
    print(close_strings('abc', 'bca'))  # True
    print(close_strings('a', 'bb'))     # False
