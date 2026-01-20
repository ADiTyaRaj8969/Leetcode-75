// Topic: Greedy / Intervals
// Minimum Number of Arrows to Burst Balloons: sort intervals by end and greedily shoot
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points)
{
    if (points.empty())
        return 0;
    sort(points.begin(), points.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    int arrows = 1;
    long long lastEnd = points[0][1];
    for (int i = 1; i < points.size(); ++i)
    {
        if (points[i][0] > lastEnd)
        {
            arrows++;
            lastEnd = points[i][1];
        }
    }
    return arrows;
}

int main()
{
    vector<vector<int>> a1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(a1) << "\n";  // 2
    vector<vector<int>> a2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << findMinArrowShots(a2) << "\n";  // 4
    return 0;
}
