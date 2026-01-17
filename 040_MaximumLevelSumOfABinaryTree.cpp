// Topic: Binary Tree / BFS
// Maximum Level Sum of a Binary Tree: Find level with maximum sum of node values.
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

int maxLevelSum(TreeNode* root)
{
    if (!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    long long bestSum = LLONG_MIN;
    int bestLevel = 1, level = 1;
    while (!q.empty())
    {
        int sz = q.size();
        long long sum = 0;
        for (int i = 0; i < sz; ++i)
        {
            auto n = q.front();
            q.pop();
            sum += n->val;
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        if (sum > bestSum)
        {
            bestSum = sum;
            bestLevel = level;
        }
        ++level;
    }
    return bestLevel;
}

int main()
{
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(7);
    r->right = new TreeNode(0);
    r->left->left = new TreeNode(7);
    r->left->right = new TreeNode(-8);
    cout << maxLevelSum(r) << "\n";  // 2 (level with sum 7)
    TreeNode* r2 = new TreeNode(-100);
    r2->left = new TreeNode(-200);
    r2->right = new TreeNode(-300);
    cout << maxLevelSum(r2) << "\n";
    return 0;
}
