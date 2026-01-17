"""
Topic: Tree / BFS
Binary Tree Right Side View: collect rightmost node at each level via BFS
Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import Optional, List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def right_side_view(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    q = deque([root])
    res = []
    while q:
        sz = len(q)
        for i in range(sz):
            node = q.popleft()
            if i == sz-1: res.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
    return res

if __name__ == '__main__':
    root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3, None, TreeNode(4)))
    print(right_side_view(root))  # [1,3,4]
    print(right_side_view(None))  # []
