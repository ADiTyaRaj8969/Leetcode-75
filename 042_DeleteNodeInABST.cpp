// Topic: BST / Recursion
// Delete Node in a BST: Remove a node with given key and return new root.
// Time Complexity: O(h)
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

TreeNode* findMin(TreeNode* node)
{
    while (node->left) node = node->left;
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
        {
            TreeNode* r = root->right;
            delete root;
            return r;
        }
        if (!root->right)
        {
            TreeNode* l = root->left;
            delete root;
            return l;
        }
        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}

void inorder(TreeNode* r)
{
    if (!r)
        return;
    inorder(r->left);
    cout << r->val << ' ';
    inorder(r->right);
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    inorder(root);
    cout << "\n";
    root = deleteNode(root, 3);
    inorder(root);
    cout << "\n";
    root = deleteNode(root, 5);
    inorder(root);
    cout << "\n";
    return 0;
}
