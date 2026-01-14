"""
Topic: Sliding Window / Two Pointers
Max Consecutive Ones III: longest subarray with at most k zeros
Time Complexity: O(n)
Space Complexity: O(1)
"""

def longest_ones(nums, k):
    left = 0
    zeros = 0
    best = 0
    for right, v in enumerate(nums):
        if v == 0:
            zeros += 1
        while zeros > k:
            if nums[left] == 0:
                zeros -= 1
            left += 1
        best = max(best, right - left + 1)
    return best


if __name__ == '__main__':
    print(longest_ones([1,1,1,0,0,0,1,1,1,1,0], 2))  # 6
    print(longest_ones([0,0,1,1,0,0,1,1,1,0,1,1], 3))  # 6
