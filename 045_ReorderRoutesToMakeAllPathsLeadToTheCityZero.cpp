// Topic: Graph / DFS
// Reorder Routes to Make All Paths Lead to the City Zero: Count minimum edges to reverse so all
// nodes reach 0. Time Complexity: O(n) Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections)
{
    vector<vector<pair<int, int>>> adj(
        n);  // neighbor, cost(0 if correct toward neighbor, 1 if needs reversal)
    for (auto& c : connections)
    {
        int a = c[0], b = c[1];
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 0});
    }
    vector<char> vis(n, 0);
    int ans = 0;
    stack<int> st;
    st.push(0);
    vis[0] = 1;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        for (auto [v, cost] : adj[u])
            if (!vis[v])
            {
                vis[v] = 1;
                ans += cost;
                st.push(v);
            }
    }
    return ans;
}

int main()
{
    vector<vector<int>> c1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << minReorder(6, c1) << "\n";  // expected 3
    vector<vector<int>> c2 = {{1, 0}, {2, 0}};
    cout << minReorder(3, c2) << "\n";  // 0
    return 0;
}
