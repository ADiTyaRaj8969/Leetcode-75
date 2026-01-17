"""
Topic: Binary Search Tree
Problem: Search in a Binary Search Tree
Description: Return the subtree rooted with the node that has the given value.
Time: O(h) where h is tree height
Space: O(h) recursion stack
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def searchBST(root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    # iterative BST search
    node = root
    while node:
        if node.val == val:
            return node
        node = node.left if val < node.val else node.right
    return None


def build(vals):
    if not vals:
        return None
    nodes = [TreeNode(v) if v is not None else None for v in vals]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root


if __name__ == '__main__':
    # Test 1
    root = build([4,2,7,1,3])
    res = searchBST(root, 2)
    print(res.val if res else None)  # 2

    # Test 2 - missing
    root = build([4,2,7,1,3])
    print(searchBST(root, 5))  # None
