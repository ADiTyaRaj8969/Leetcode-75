"""
Topic: Array / Simple
Kids With the Greatest Number of Candies: check if each kid can reach max after extra candies
Time Complexity: O(n)
Space Complexity: O(n)
"""

def kids_with_candies(candies, extra_candies):
    mx = max(candies) if candies else 0
    return [c + extra_candies >= mx for c in candies]


if __name__ == '__main__':
    print(kids_with_candies([2,3,5,1,3], 3))  # [True, True, True, False, True]
    print(kids_with_candies([4,2,1,1,2], 1))  # [True, False, False, False, False]
