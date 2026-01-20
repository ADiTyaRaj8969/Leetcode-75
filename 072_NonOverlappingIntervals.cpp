// Topic: Greedy / Intervals
// Non-overlapping Intervals: remove minimum intervals so remaining intervals are non-overlapping
// Approach: sort by end and greedily keep intervals with earliest end
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    if (intervals.empty())
        return 0;
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    int keep = 1;
    int lastEnd = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] >= lastEnd)
        {
            keep++;
            lastEnd = intervals[i][1];
        }
    }
    return intervals.size() - keep;
}

int main()
{
    vector<vector<int>> a1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(a1) << "\n";  // 1
    vector<vector<int>> a2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << eraseOverlapIntervals(a2) << "\n";  // 2
    return 0;
}
