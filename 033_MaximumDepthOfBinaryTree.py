"""
Topic: Tree / DFS
Maximum Depth of Binary Tree: recursive depth-first search
Time Complexity: O(n)
Space Complexity: O(h) recursion
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max_depth(root: Optional[TreeNode]) -> int:
    if not root: return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))

if __name__ == '__main__':
    # tree: [3,9,20,null,null,15,7]
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(max_depth(root))  # 3
    print(max_depth(None))  # 0
