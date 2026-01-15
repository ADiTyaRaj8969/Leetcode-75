"""
Topic: Tree / DFS
Longest ZigZag Path in Binary Tree: DFS tracking direction and length
Time Complexity: O(n)
Space Complexity: O(h)
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def longest_zigzag(root: Optional[TreeNode]) -> int:
    best = 0
    def dfs(node):
        nonlocal best
        if not node: return (-1, -1)  # (left_len, right_len)
        left = dfs(node.left)
        right = dfs(node.right)
        cur_left = 1 + left[1]
        cur_right = 1 + right[0]
        best = max(best, cur_left, cur_right)
        return (cur_left, cur_right)
    dfs(root)
    return best

if __name__ == '__main__':
    # example small tree
    root = TreeNode(1, TreeNode(2, None, TreeNode(3, TreeNode(4), TreeNode(5))), None)
    print(longest_zigzag(root))  # example value
    print(longest_zigzag(None))  # 0
