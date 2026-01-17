// Topic: BFS / Grid
// Nearest Exit from Entrance in Maze: Shortest path from entrance to any exit (edges are steps,
// can't use entrance as exit) Time Complexity: O(R*C) Space Complexity: O(R*C)

#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{
    int R = maze.size(), C = maze[0].size();
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    vector<vector<int>> dist(R, vector<int>(C, -1));
    dist[entrance[0]][entrance[1]] = 0;
    vector<int> dirs = {0, 1, 0, -1, 0};
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if (!(r == entrance[0] && c == entrance[1]) &&
            (r == 0 || c == 0 || r == R - 1 || c == C - 1))
            return dist[r][c];
        for (int k = 0; k < 4; ++k)
        {
            int nr = r + dirs[k], nc = c + dirs[k + 1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && maze[nr][nc] == '.' && dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<char>> m1 = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> e1 = {1, 2};
    cout << nearestExit(m1, e1) << "\n";  // 1
    vector<vector<char>> m2 = {{'+', '+'}, {'.', '.'}};
    vector<int> e2 = {1, 0};
    cout << nearestExit(m2, e2) << "\n";  // 2
    return 0;
}
