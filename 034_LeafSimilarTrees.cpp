// Topic: Binary Tree / DFS
// Leaf-Similar Trees: Check if two binary trees have the same sequence of leaf node values.
// Time Complexity: O(n+m)
// Space Complexity: O(h1+h2)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leaves(TreeNode* root, vector<int>& out)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        out.push_back(root->val);
        return;
    }
    leaves(root->left, out);
    leaves(root->right, out);
}

bool leafSimilar(TreeNode* r1, TreeNode* r2)
{
    vector<int> a, b;
    leaves(r1, a);
    leaves(r2, b);
    return a == b;
}

int main()
{
    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(5);
    a->right = new TreeNode(1);
    a->left->left = new TreeNode(6);
    a->left->right = new TreeNode(2);
    a->left->right->left = new TreeNode(7);
    a->left->right->right = new TreeNode(4);
    TreeNode* b = new TreeNode(3);
    b->left = new TreeNode(5);
    b->right = new TreeNode(1);
    b->left->left = new TreeNode(6);
    b->left->right = new TreeNode(7);
    b->right->left = new TreeNode(4);
    b->right->right = new TreeNode(2);
    cout << (leafSimilar(a, b) ? "true" : "false") << "\n";  // true
    TreeNode* c = new TreeNode(1);
    c->left = new TreeNode(2);
    c->right = new TreeNode(3);
    cout << (leafSimilar(a, c) ? "true" : "false") << "\n";  // false
    return 0;
}
