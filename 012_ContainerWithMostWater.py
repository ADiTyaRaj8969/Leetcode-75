"""
Topic: Two Pointers / Greedy
Container With Most Water: use two pointers and move the smaller height
Time Complexity: O(n)
Space Complexity: O(1)
"""

def max_area(height):
    i, j = 0, len(height)-1
    best = 0
    while i < j:
        best = max(best, min(height[i], height[j]) * (j - i))
        if height[i] < height[j]:
            i += 1
        else:
            j -= 1
    return best


if __name__ == '__main__':
    print(max_area([1,8,6,2,5,4,8,3,7]))  # 49
    print(max_area([1,1]))  # 1
