"""
Topic: Greedy / Intervals
Problem: Minimum Number of Arrows to Burst Balloons
Description: Shoot arrows at min number of points to hit all interval balloons.
Time: O(n log n)
Space: O(1)
"""

from typing import List


def findMinArrowShots(points: List[List[int]]) -> int:
    if not points:
        return 0
    points.sort(key=lambda x: x[1])
    arrows = 1
    end = points[0][1]
    for s, e in points[1:]:
        if s > end:
            arrows += 1
            end = e
    return arrows


if __name__ == '__main__':
    print(findMinArrowShots([[10,16],[2,8],[1,6],[7,12]]))  # 2
    print(findMinArrowShots([[1,2],[3,4],[5,6],[7,8]]))  # 4
