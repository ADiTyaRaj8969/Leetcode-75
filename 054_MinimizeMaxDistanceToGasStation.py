"""
Topic: Binary Search / Greedy
Problem: Minimize Max Distance to Gas Station
Description: Binary search the maximum allowed distance and check feasibility.
Time: O(n log W) where W is search range precision
Space: O(1)
"""

from typing import List


def minmaxGasDist(stations: List[int], k: int) -> float:
    def feasible(d: float) -> bool:
        # count how many extra stations needed for gap with max distance d
        need = 0
        for i in range(1, len(stations)):
            gap = stations[i] - stations[i-1]
            need += int(gap // d)  # number of pieces larger than d
            if need > k:
                return False
        return need <= k

    lo, hi = 1e-6, stations[-1] - stations[0]
    for _ in range(50):
        mid = (lo + hi) / 2
        if feasible(mid):
            hi = mid
        else:
            lo = mid
    return hi


if __name__ == '__main__':
    print(round(minmaxGasDist([1,2,3,4,5,6,7,8,9,10], 9), 6))
    print(round(minmaxGasDist([23, 32, 40, 47, 79, 84, 100], 1), 6))
