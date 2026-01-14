"""
Topic: Prefix Sum
Find Pivot Index: find index where left sum equals right sum
Time Complexity: O(n)
Space Complexity: O(1)
"""

def pivot_index(nums):
    total = sum(nums)
    left = 0
    for i, v in enumerate(nums):
        if left == total - left - v:
            return i
        left += v
    return -1


if __name__ == '__main__':
    print(pivot_index([1,7,3,6,5,6]))  # 3
    print(pivot_index([1,2,3]))  # -1
