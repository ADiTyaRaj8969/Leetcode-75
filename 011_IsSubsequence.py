"""
Topic: Two Pointers / String
Is Subsequence: check if s is subsequence of t using two pointers
Time Complexity: O(n + m)
Space Complexity: O(1)
"""

def is_subsequence(s: str, t: str) -> bool:
    i = 0
    for c in t:
        if i < len(s) and s[i] == c:
            i += 1
            if i == len(s):
                return True
    return i == len(s)


if __name__ == '__main__':
    print(is_subsequence('abc', 'ahbgdc'))  # True
    print(is_subsequence('axc', 'ahbgdc'))  # False
