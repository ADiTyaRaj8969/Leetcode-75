// Topic: Graph / Union-Find or DFS
// Number of Provinces: Count connected components in an adjacency matrix.
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int findp(vector<int>& p, int x)
{
    return p[x] == x ? x : p[x] = findp(p, p[x]);
}

int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (isConnected[i][j])
                p[findp(p, j)] = findp(p, i);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) s.insert(findp(p, i));
    return s.size();
}

int main()
{
    vector<vector<int>> g1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(g1) << "\n";  // 2
    vector<vector<int>> g2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(g2) << "\n";  // 3
    return 0;
}
