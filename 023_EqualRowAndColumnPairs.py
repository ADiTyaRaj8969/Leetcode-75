"""
Topic: Matrix / Hashing
Equal Row and Column Pairs: count how many rows equal columns
Time Complexity: O(n^2)
Space Complexity: O(n^2) for map
"""

from collections import Counter

def equal_pairs(grid):
    n = len(grid)
    rows = Counter(tuple(row) for row in grid)
    cols = Counter(tuple(grid[r][c] for r in range(n)) for c in range(n))
    res = 0
    for k, v in rows.items():
        res += v * cols.get(k, 0)
    return res


if __name__ == '__main__':
    print(equal_pairs([[3,2,1],[1,7,6],[2,7,7]]))  # 1
    print(equal_pairs([[1,2],[2,1]]))  # 2
