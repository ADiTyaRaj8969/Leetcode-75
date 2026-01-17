"""
Topic: Tree / BFS
Maximum Level Sum of a Binary Tree: find level with max sum using BFS
Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max_level_sum(root: Optional[TreeNode]) -> int:
    if not root: return 0
    q = deque([root])
    best_sum = float('-inf')
    best_level = 1
    level = 0
    while q:
        level += 1
        s = 0
        for _ in range(len(q)):
            node = q.popleft()
            s += node.val
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        if s > best_sum:
            best_sum = s; best_level = level
    return best_level

if __name__ == '__main__':
    # [1,7,0,7,-8,null,null]
    root = TreeNode(1, TreeNode(7, TreeNode(7), TreeNode(-8)), TreeNode(0))
    print(max_level_sum(root))  # 2
    print(max_level_sum(None))  # 0
