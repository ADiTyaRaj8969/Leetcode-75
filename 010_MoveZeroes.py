"""
Topic: Two Pointers / In-place
Move Zeroes: move zeroes to end while preserving order
Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List

def move_zeroes(nums: List[int]) -> List[int]:
    j = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[j], nums[i] = nums[i], nums[j]
            j += 1
    return nums


if __name__ == '__main__':
    print(move_zeroes([0,1,0,3,12]))  # [1,3,12,0,0]
    print(move_zeroes([0,0,1]))      # [1,0,0]
