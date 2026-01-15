"""
Topic: Tree / Recursion
Lowest Common Ancestor of a Binary Tree: classic recursive approach
Time Complexity: O(n)
Space Complexity: O(h)
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowest_common_ancestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    if not root or root == p or root == q:
        return root
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right:
        return root
    return left if left else right

if __name__ == '__main__':
    # build simple tree
    a = TreeNode(3)
    a.left = TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4)))
    a.right = TreeNode(1, TreeNode(0), TreeNode(8))
    p = a.left
    q = a.right
    print(lowest_common_ancestor(a, p, q).val)  # 3
    print(lowest_common_ancestor(a, a.left.left, a.left.right.right).val)  # 5
