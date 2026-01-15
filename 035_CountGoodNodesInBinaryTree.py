"""
Topic: Tree / DFS
Count Good Nodes in Binary Tree: node is good if its value >= max on path from root
Time Complexity: O(n)
Space Complexity: O(h)
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def good_nodes(root: Optional[TreeNode]) -> int:
    def dfs(node, mx):
        if not node: return 0
        cnt = 1 if node.val >= mx else 0
        mx2 = max(mx, node.val)
        cnt += dfs(node.left, mx2) + dfs(node.right, mx2)
        return cnt
    return dfs(root, float('-inf'))

if __name__ == '__main__':
    root = TreeNode(3, TreeNode(1, TreeNode(3)), TreeNode(4, TreeNode(1), TreeNode(5)))
    print(good_nodes(root))  # 4
    print(good_nodes(None))  # 0
