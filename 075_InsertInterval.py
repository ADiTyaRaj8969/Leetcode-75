"""
Topic: Intervals
Problem: Insert Interval
Description: Insert a new interval and merge overlapping intervals.
Time: O(n)
Space: O(n)
"""

from typing import List


def insert(intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    res = []
    i = 0
    n = len(intervals)
    # add all intervals ending before newInterval starts
    while i < n and intervals[i][1] < newInterval[0]:
        res.append(intervals[i]); i += 1
    # merge overlapping
    while i < n and intervals[i][0] <= newInterval[1]:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i += 1
    res.append(newInterval)
    # add rest
    while i < n:
        res.append(intervals[i]); i += 1
    return res


if __name__ == '__main__':
    print(insert([[1,3],[6,9]], [2,5]))  # [[1,5],[6,9]]
    print(insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]))  # [[1,2],[3,10],[12,16]]
