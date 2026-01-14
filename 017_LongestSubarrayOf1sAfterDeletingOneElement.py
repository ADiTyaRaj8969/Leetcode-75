"""
Topic: Sliding Window / Two Pointers
Longest Subarray of 1's After Deleting One Element: track window with at most one zero
Time Complexity: O(n)
Space Complexity: O(1)
"""

def longest_subarray_after_deletion(nums):
    left = 0
    zero_count = 0
    best = 0
    for right, v in enumerate(nums):
        if v == 0:
            zero_count += 1
        while zero_count > 1:
            if nums[left] == 0:
                zero_count -= 1
            left += 1
        best = max(best, right - left)
    return best


if __name__ == '__main__':
    print(longest_subarray_after_deletion([1,1,0,1]))  # 3
    print(longest_subarray_after_deletion([0,1,1,1,0,1,1,0,1]))  # 5
