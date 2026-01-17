"""
Topic: Graph / DFS
Problem: Reorder Routes to Make All Paths Lead to the City Zero
Description: Count how many directed edges need reversal so every node can reach node 0.
Time: O(n)
Space: O(n)
"""

from typing import List


def minReorder(n: int, connections: List[List[int]]) -> int:
    adj = [[] for _ in range(n)]
    for a, b in connections:
        adj[a].append((b, 1))  # original direction a->b (needs reversal if used)
        adj[b].append((a, 0))  # reverse edge marked 0 (no reversal needed)

    seen = [False]*n
    def dfs(u):
        seen[u] = True
        res = 0
        for v, cost in adj[u]:
            if not seen[v]:
                res += cost + dfs(v)
        return res

    return dfs(0)


if __name__ == '__main__':
    print(minReorder(6, [[0,1],[1,3],[2,3],[4,0],[4,5]]))  # 3
    print(minReorder(5, [[1,0],[1,2],[3,2],[3,4]]))  # 2
