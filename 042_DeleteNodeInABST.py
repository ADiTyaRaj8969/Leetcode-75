"""
Topic: Binary Search Tree
Problem: Delete Node in a BST
Description: Delete node with given key and return new root.
Time: O(h) where h is tree height
Space: O(h) recursion
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def deleteNode(root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
    if not root:
        return None
    if key < root.val:
        root.left = deleteNode(root.left, key)
    elif key > root.val:
        root.right = deleteNode(root.right, key)
    else:
        # found node
        if not root.left:
            return root.right
        if not root.right:
            return root.left
        # two children: replace with inorder successor
        succ = root.right
        while succ.left:
            succ = succ.left
        root.val = succ.val
        root.right = deleteNode(root.right, succ.val)
    return root


def build(vals):
    if not vals: return None
    nodes = [TreeNode(v) if v is not None else None for v in vals]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root


def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []


if __name__ == '__main__':
    root = build([5,3,6,2,4,None,7])
    root = deleteNode(root, 3)
    print(inorder(root))  # [2,4,5,6,7]

    root = build([5,3,6,2,4,None,7])
    root = deleteNode(root, 5)
    print(inorder(root))  # [2,3,4,6,7]
