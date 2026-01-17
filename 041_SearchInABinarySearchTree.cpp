// Topic: BST / Recursion
// Search in a Binary Search Tree: Find a node with given value in BST.
// Time Complexity: O(h) where h is tree height
// Space Complexity: O(h) recursion

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    if (val < root->val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    auto r = searchBST(root, 2);
    cout << (r ? r->val : -1) << '\n';                             // 2
    cout << (searchBST(root, 5) ? "found" : "not found") << '\n';  // not found
    return 0;
}
