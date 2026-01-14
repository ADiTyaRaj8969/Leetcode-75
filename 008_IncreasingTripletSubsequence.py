"""
Topic: Greedy / Two Variables
Increasing Triplet Subsequence: maintain two smallest values
Time Complexity: O(n)
Space Complexity: O(1)
"""

def increasing_triplet(nums):
    first = second = float('inf')
    for x in nums:
        if x <= first:
            first = x
        elif x <= second:
            second = x
        else:
            return True
    return False


if __name__ == '__main__':
    print(increasing_triplet([1,2,3,4,5]))  # True
    print(increasing_triplet([5,4,3,2,1]))  # False
