// Topic: Binary Tree / DFS
// Maximum Depth of Binary Tree: Find the number of nodes along the longest path from the root to a
// leaf. Time Complexity: O(n) Space Complexity: O(h) recursion

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepth(root) << "\n";     // 3
    cout << maxDepth(nullptr) << "\n";  // 0
    return 0;
}
