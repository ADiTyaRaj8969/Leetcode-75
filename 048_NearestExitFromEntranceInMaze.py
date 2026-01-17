"""
Topic: BFS / Grid
Problem: Nearest Exit From Entrance in Maze
Description: BFS to find minimal steps to nearest exit (not the entrance cell).
Time: O(m*n)
Space: O(m*n)
"""

from collections import deque
from typing import List


def nearestExit(maze: List[List[str]], entrance: List[int]) -> int:
    R, C = len(maze), len(maze[0])
    er, ec = entrance
    q = deque([(er, ec, 0)])
    seen = {(er, ec)}
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        r, c, d = q.popleft()
        # skip checking entrance as exit
        if (r,c) != (er,ec) and (r==0 or c==0 or r==R-1 or c==C-1):
            return d
        for dr, dc in dirs:
            nr, nc = r+dr, c+dc
            if 0<=nr<R and 0<=nc<C and maze[nr][nc]=='.' and (nr,nc) not in seen:
                seen.add((nr,nc))
                q.append((nr,nc,d+1))
    return -1


if __name__ == '__main__':
    m = [["+","+","."],[".",".","."],["+","+","+"]]
    print(nearestExit(m, [1,0]))  # 2
    m2 = [["+","+","+"],["+",".","+"],["+","+","+"]]
    print(nearestExit(m2, [1,1]))  # -1
