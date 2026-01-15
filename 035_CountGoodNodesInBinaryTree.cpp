// Topic: Binary Tree / DFS
// Count Good Nodes in Binary Tree: Count nodes greater than or equal to max on path from root.
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

int dfs(TreeNode* node, int curMax)
{
    if (!node)
        return 0;
    int cnt = (node->val >= curMax) ? 1 : 0;
    curMax = max(curMax, node->val);
    cnt += dfs(node->left, curMax);
    cnt += dfs(node->right, curMax);
    return cnt;
}

int goodNodes(TreeNode* root)
{
    return dfs(root, INT_MIN);
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << goodNodes(root) << "\n";  // 4
    TreeNode* r2 = new TreeNode(3);
    r2->left = new TreeNode(3);
    r2->right = new TreeNode(3);
    cout << goodNodes(r2) << "\n";  // 3
    return 0;
}
