"""
Topic: Sliding Window
Maximum Number of Vowels in Substring of Given Length: sliding window counting vowels
Time Complexity: O(n)
Space Complexity: O(1)
"""

def max_vowels(s: str, k: int) -> int:
    vowels = set('aeiou')
    cur = sum(1 for c in s[:k] if c in vowels)
    best = cur
    for i in range(k, len(s)):
        if s[i-k] in vowels: cur -= 1
        if s[i] in vowels: cur += 1
        best = max(best, cur)
    return best


if __name__ == '__main__':
    print(max_vowels('abciiidef', 3))  # 3
    print(max_vowels('aeiou', 2))  # 2
