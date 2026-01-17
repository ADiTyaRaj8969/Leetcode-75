// Topic: BFS / Grid
// Rotting Oranges: Minimum time for all fresh oranges to become rotten, or -1 if impossible.
// Time Complexity: O(R*C)
// Space Complexity: O(R*C)

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int R = grid.size();
    if (R == 0)
        return -1;
    int C = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                ++fresh;
        }
    if (fresh == 0)
        return 0;
    int minutes = 0;
    vector<int> dirs = {0, 1, 0, -1, 0};
    while (!q.empty())
    {
        int sz = q.size();
        bool progressed = false;
        for (int t = 0; t < sz; ++t)
        {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int nr = r + dirs[k], nc = c + dirs[k + 1];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    --fresh;
                    progressed = true;
                }
            }
        }
        if (progressed)
            ++minutes;
    }
    return fresh == 0 ? minutes : -1;
}

int main()
{
    vector<vector<int>> g1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(g1) << "\n";  // 4
    vector<vector<int>> g2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << orangesRotting(g2) << "\n";  // -1
    vector<vector<int>> g3 = {{0, 2}};
    cout << orangesRotting(g3) << "\n";  // 0
    return 0;
}
