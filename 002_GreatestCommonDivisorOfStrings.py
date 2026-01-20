"""
Topic: String / Math
Greatest Common Divisor of Strings: use gcd on lengths and check concatenation property
Time Complexity: O(n + m)
Space Complexity: O(n + m)
"""

import math

def gcd_of_strings(str1: str, str2: str) -> str:
    if str1 + str2 != str2 + str1:
        return ''
    l = math.gcd(len(str1), len(str2))
    return str1[:l]


if __name__ == '__main__':
    print(gcd_of_strings('ABCABC', 'ABC'))  # 'ABC'
    print(gcd_of_strings('ABAB', 'AB'))      # 'AB'
