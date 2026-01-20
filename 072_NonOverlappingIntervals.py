"""
Topic: Greedy / Intervals
Problem: Non-overlapping Intervals
Description: Minimum number of intervals to remove so that the rest are non-overlapping.
Time: O(n log n)
Space: O(1)
"""

from typing import List


def eraseOverlapIntervals(intervals: List[List[int]]) -> int:
    if not intervals:
        return 0
    intervals.sort(key=lambda x: x[1])
    count = 0
    end = intervals[0][1]
    for s, e in intervals[1:]:
        if s < end:
            count += 1
        else:
            end = e
    return count


if __name__ == '__main__':
    print(eraseOverlapIntervals([[1,2],[2,3],[3,4],[1,3]]))  # 1
    print(eraseOverlapIntervals([[1,2],[1,2],[1,2]]))  # 2
