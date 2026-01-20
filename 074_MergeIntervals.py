"""
Topic: Intervals / Sorting
Problem: Merge Intervals
Description: Merge all overlapping intervals.
Time: O(n log n)
Space: O(n)
"""

from typing import List


def merge(intervals: List[List[int]]) -> List[List[int]]:
    if not intervals:
        return []
    intervals.sort(key=lambda x: x[0])
    res = [intervals[0]]
    for s, e in intervals[1:]:
        last_s, last_e = res[-1]
        if s <= last_e:
            res[-1][1] = max(last_e, e)
        else:
            res.append([s, e])
    return res


if __name__ == '__main__':
    print(merge([[1,3],[2,6],[8,10],[15,18]]))  # [[1,6],[8,10],[15,18]]
    print(merge([[1,4],[4,5]]))  # [[1,5]]
