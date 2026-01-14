"""
Topic: Prefix Sum
Find The Highest Altitude: prefix sum of gains
Time Complexity: O(n)
Space Complexity: O(1)
"""

def largest_altitude(gains):
    cur = 0
    best = 0
    for g in gains:
        cur += g
        best = max(best, cur)
    return best


if __name__ == '__main__':
    print(largest_altitude([-5,1,5,0,-7]))  # 1
    print(largest_altitude([ -4, -3, -2, -1]))  # 0
