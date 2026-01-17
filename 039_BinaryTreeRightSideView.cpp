// Topic: Binary Tree / BFS
// Binary Tree Right Side View: List nodes visible when looking from the right.
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

vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            auto node = q.front();
            q.pop();
            if (i == sz - 1)
                res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return res;
}

int main()
{
    TreeNode* r = new TreeNode(1);
    r->right = new TreeNode(3);
    r->left = new TreeNode(2);
    r->left->right = new TreeNode(5);
    r->right->right = new TreeNode(4);
    auto v = rightSideView(r);
    for (int x : v) cout << x << ' ';
    cout << "\n";  // 1 3 4
    TreeNode* r2 = new TreeNode(1);
    cout << rightSideView(r2)[0] << "\n";
    return 0;
}
