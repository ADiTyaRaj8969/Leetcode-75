"""
Topic: Sliding Window
Maximum Average Subarray I: sliding window of fixed size k
Time Complexity: O(n)
Space Complexity: O(1)
"""

def maximum_average_subarray(nums, k):
    window = sum(nums[:k])
    best = window
    for i in range(k, len(nums)):
        window += nums[i] - nums[i-k]
        best = max(best, window)
    return best / k


if __name__ == '__main__':
    print(maximum_average_subarray([1,12,-5,-6,50,3], 4))  # 12.75
    print(maximum_average_subarray([5], 1))  # 5.0
