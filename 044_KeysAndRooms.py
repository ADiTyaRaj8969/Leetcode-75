"""
Topic: Graph / DFS
Problem: Keys and Rooms
Description: Determine if all rooms are reachable from room 0 given keys.
Time: O(n + sum(keys))
Space: O(n)
"""

from typing import List


def canVisitAllRooms(rooms: List[List[int]]) -> bool:
    n = len(rooms)
    seen = [False]*n
    stack = [0]
    seen[0] = True
    while stack:
        node = stack.pop()
        for k in rooms[node]:
            if not seen[k]:
                seen[k] = True
                stack.append(k)
    return all(seen)


if __name__ == '__main__':
    print(canVisitAllRooms([[1],[2],[3],[]]))  # True
    print(canVisitAllRooms([[1,3],[3,0,1],[2],[0]]))  # False
