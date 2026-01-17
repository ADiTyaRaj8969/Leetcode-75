"""
Topic: Graph / DFS
Problem: Evaluate Division
Description: Evaluate division queries using graph of multiplicative weights.
Time: O(Q * (V+E)) worst-case
Space: O(V+E)
"""

from typing import List, Dict, Tuple


def calcEquation(equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    g = {}
    for (a, b), w in zip(equations, values):
        g.setdefault(a, []).append((b, w))
        g.setdefault(b, []).append((a, 1.0 / w))

    def dfs(src, dst, seen: set) -> float:
        if src not in g or dst not in g:
            return -1.0
        if src == dst:
            return 1.0
        seen.add(src)
        for nei, w in g[src]:
            if nei in seen:
                continue
            sub = dfs(nei, dst, seen)
            if sub != -1.0:
                return w * sub
        return -1.0

    res = []
    for u, v in queries:
        res.append(dfs(u, v, set()))
    return res


if __name__ == '__main__':
    eq = [["a","b"],["b","c"]]
    vals = [2.0,3.0]
    qs = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    print(calcEquation(eq, vals, qs))  # [6.0,0.5,-1.0,1.0,-1.0]
