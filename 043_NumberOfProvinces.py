"""
Topic: Graph / DFS / Union-Find
Problem: Number of Provinces
Description: Count connected components in an undirected adjacency matrix.
Time: O(n^2)
Space: O(n)
"""

from typing import List


def findCircleNum(isConnected: List[List[int]]) -> int:
    n = len(isConnected)
    visited = [False]*n

    def dfs(i):
        visited[i] = True
        for j in range(n):
            if isConnected[i][j] and not visited[j]:
                dfs(j)

    cnt = 0
    for i in range(n):
        if not visited[i]:
            cnt += 1
            dfs(i)
    return cnt


if __name__ == '__main__':
    print(findCircleNum([[1,1,0],[1,1,0],[0,0,1]]))  # 2
    print(findCircleNum([[1,0,0],[0,1,0],[0,0,1]]))  # 3
