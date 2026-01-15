// Topic: Binary Tree / Prefix sum + DFS
// Path Sum III: Count number of paths that sum to target (paths can start/end anywhere downward).
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* node, long long curr, int target, unordered_map<long long, int>& pref)
{
    if (!node)
        return 0;
    curr += node->val;
    int cnt = 0;
    if (pref.count(curr - target))
        cnt += pref[curr - target];
    ++pref[curr];
    cnt += dfs(node->left, curr, target, pref);
    cnt += dfs(node->right, curr, target, pref);
    --pref[curr];
    return cnt;
}

int pathSum(TreeNode* root, int targetSum)
{
    unordered_map<long long, int> pref;
    pref[0] = 1;
    return dfs(root, 0, targetSum, pref);
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    root->right->right = new TreeNode(11);
    cout << pathSum(root, 8) << "\n";  // 3
    TreeNode* r2 = new TreeNode(1);
    r2->left = new TreeNode(-2);
    r2->right = new TreeNode(-3);
    cout << pathSum(r2, -1) << "\n";
    return 0;
}
