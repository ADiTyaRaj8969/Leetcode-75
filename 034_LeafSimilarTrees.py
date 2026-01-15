"""
Topic: Tree / DFS
Leaf-Similar Trees: compare leaf traversal sequences
Time Complexity: O(n + m)
Space Complexity: O(h + k)
"""

from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def leaf_sequence(root: Optional[TreeNode], out: List[int]):
    if not root: return
    if not root.left and not root.right:
        out.append(root.val); return
    leaf_sequence(root.left, out)
    leaf_sequence(root.right, out)

def leaf_similar(root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
    a, b = [], []
    leaf_sequence(root1, a)
    leaf_sequence(root2, b)
    return a == b

if __name__ == '__main__':
    # tree1 leaves: [6,7,4,2]
    t1 = TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))), TreeNode(1))
    t2 = TreeNode(3, TreeNode(5, TreeNode(6), TreeNode(2, TreeNode(7), TreeNode(4))), TreeNode(1))
    print(leaf_similar(t1, t2))  # True
    print(leaf_similar(t1, TreeNode(1)))  # False
