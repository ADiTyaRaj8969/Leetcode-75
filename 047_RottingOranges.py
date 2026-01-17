"""
Topic: BFS / Grid
Problem: Rotting Oranges
Description: Multi-source BFS to compute minutes until all oranges rot.
Time: O(m*n)
Space: O(m*n)
"""

from collections import deque
from typing import List


def orangesRotting(grid: List[List[int]]) -> int:
    R, C = len(grid), len(grid[0])
    q = deque()
    fresh = 0
    for r in range(R):
        for c in range(C):
            if grid[r][c] == 2:
                q.append((r, c))
            elif grid[r][c] == 1:
                fresh += 1
    if fresh == 0:
        return 0
    minutes = 0
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        minutes += 1
        for _ in range(len(q)):
            r, c = q.popleft()
            for dr, dc in dirs:
                nr, nc = r+dr, c+dc
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    q.append((nr, nc))
        if fresh == 0:
            return minutes
    return -1


if __name__ == '__main__':
    print(orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))  # 4
    print(orangesRotting([[2,1,1],[0,1,1],[1,0,1]]))  # -1
