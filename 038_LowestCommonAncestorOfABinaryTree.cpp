// Topic: Binary Tree / Recursion
// Lowest Common Ancestor of a Binary Tree: Find lowest shared ancestor of two nodes.
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode* L = lowestCommonAncestor(root->left, p, q);
    TreeNode* R = lowestCommonAncestor(root->right, p, q);
    if (L && R)
        return root;
    return L ? L : R;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    cout << lowestCommonAncestor(root, root->left, root->right)->val << "\n";               // 3
    cout << lowestCommonAncestor(root, root->left, root->left->right->right)->val << "\n";  // 5
    return 0;
}
