"""
Topic: Tree / Prefix Sum + DFS
Path Sum III: count paths summing to target using prefix-sum hashmap
Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import Optional
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def path_sum(root: Optional[TreeNode], target: int) -> int:
    pref = defaultdict(int)
    pref[0] = 1
    def dfs(node, cur):
        if not node: return 0
        cur += node.val
        cnt = pref[cur - target]
        pref[cur] += 1
        cnt += dfs(node.left, cur) + dfs(node.right, cur)
        pref[cur] -= 1
        return cnt
    return dfs(root, 0)

if __name__ == '__main__':
    # [10,5,-3,3,2,null,11,3,-2,null,1]
    root = TreeNode(10, TreeNode(5, TreeNode(3, TreeNode(3), TreeNode(-2)), TreeNode(2, None, TreeNode(1))), TreeNode(-3, None, TreeNode(11)))
    print(path_sum(root, 8))  # 3
    print(path_sum(None, 0))  # 0
