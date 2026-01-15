// Topic: Binary Tree / DFS
// Longest ZigZag Path in a Binary Tree: longest path alternating left/right.
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

int bestZ = 0;
pair<int, int> dfsZ(TreeNode* node)
{  // {len ending with left, len ending with right}
    if (!node)
        return {0, 0};
    auto L = dfsZ(node->left);
    auto R = dfsZ(node->right);
    int endLeft = 1 + L.second;  // previous step was right then left
    int endRight = 1 + R.first;
    bestZ = max({bestZ, endLeft, endRight});
    return {endLeft, endRight};
}

int longestZigZag(TreeNode* root)
{
    bestZ = 0;
    dfsZ(root);
    return bestZ == 0 ? 0 : bestZ - 1;
}

int main()
{
    TreeNode* r = new TreeNode(1);
    r->right = new TreeNode(1);
    r->right->left = new TreeNode(1);
    r->right->left->right = new TreeNode(1);
    r->right->left->right->left = new TreeNode(1);
    cout << longestZigZag(r) << "\n";  // example value
    TreeNode* r2 = new TreeNode(1);
    cout << longestZigZag(r2) << "\n";  // 0
    return 0;
}
