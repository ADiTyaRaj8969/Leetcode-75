// Topic: Matrix / Hashing
// Equal Row and Column Pairs: Count how many (row, column) pairs in a matrix are identical.
// Time Complexity: O(n^2 * log n) or O(n^2) with hashing
// Space Complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;

int equalPairs(const vector<vector<int>>& grid)
{
    int n = grid.size();
    unordered_map<string, int> rowCount;
    rowCount.reserve(n * 2);
    for (int i = 0; i < n; ++i)
    {
        string key;
        key.reserve(n * 4);
        for (int j = 0; j < n; ++j)
        {
            key += to_string(grid[i][j]);
            key.push_back(',');
        }
        ++rowCount[key];
    }
    int ans = 0;
    for (int c = 0; c < n; ++c)
    {
        string key;
        key.reserve(n * 4);
        for (int r = 0; r < n; ++r)
        {
            key += to_string(grid[r][c]);
            key.push_back(',');
        }
        auto it = rowCount.find(key);
        if (it != rowCount.end())
            ans += it->second;
    }
    return ans;
}

int main()
{
    cout << equalPairs({{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}) << '\n';  // 1
    cout << equalPairs({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) << '\n';  // 0
    cout << equalPairs({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}) << '\n';  // 9
    return 0;
}
