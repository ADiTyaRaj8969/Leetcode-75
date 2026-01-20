"""
Topic: String / Parsing
Reverse Words in a String: trim spaces, split and reverse order
Time Complexity: O(n)
Space Complexity: O(n)
"""

def reverse_words(s: str) -> str:
    parts = s.strip().split()
    return ' '.join(parts[::-1])


if __name__ == '__main__':
    print(reverse_words('  the sky   is blue  '))  # 'blue is sky the'
    print(reverse_words('a good   example'))      # 'example good a'
