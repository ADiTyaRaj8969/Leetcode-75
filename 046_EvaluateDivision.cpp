// Topic: Graph / DFS (weighted edges)
// Evaluate Division: Given equations like a/b = k, answer queries by building graph of ratios.
// Time Complexity: O(q * (n + e)) in worst case per query DFS
// Space Complexity: O(n + e)

#include <bits/stdc++.h>
using namespace std;

double dfsRatio(const string& src, const string& dst,
                unordered_map<string, vector<pair<string, double>>>& g, unordered_set<string>& vis)
{
    if (g.find(src) == g.end())
        return -1.0;
    if (src == dst)
        return 1.0;
    vis.insert(src);
    for (auto& p : g[src])
    {
        if (vis.count(p.first))
            continue;
        double sub = dfsRatio(p.first, dst, g, vis);
        if (sub > 0)
            return p.second * sub;
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals,
                            vector<vector<string>>& queries)
{
    unordered_map<string, vector<pair<string, double>>> g;
    for (size_t i = 0; i < eqs.size(); ++i)
    {
        auto& e = eqs[i];
        g[e[0]].push_back({e[1], vals[i]});
        g[e[1]].push_back({e[0], 1.0 / vals[i]});
    }
    vector<double> ans;
    ans.reserve(queries.size());
    for (auto& q : queries)
    {
        unordered_set<string> vis;
        ans.push_back(dfsRatio(q[0], q[1], g, vis));
    }
    return ans;
}

int main()
{
    vector<vector<string>> eqs = {{"a", "b"}, {"b", "c"}};
    vector<double> vals = {2.0, 3.0};
    vector<vector<string>> qs = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}};
    auto res = calcEquation(eqs, vals, qs);
    for (double d : res) cout << d << ' ';
    cout << "\n";  // 6 0.5 -1 1
    return 0;
}
