"""
Topic: Set / Array
Find The Difference of Two Arrays: return unique elements in each array
Time Complexity: O(n + m)
Space Complexity: O(n + m)
"""

def find_difference(nums1, nums2):
    s1, s2 = set(nums1), set(nums2)
    return [list(s1 - s2), list(s2 - s1)]


if __name__ == '__main__':
    print(find_difference([1,2,3], [2,4]))  # [[1,3],[4]]
    print(find_difference([1,2,3], [1,2,3]))  # [[],[]]
