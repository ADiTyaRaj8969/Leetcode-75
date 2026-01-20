// Topic: Intervals / Sorting
// Merge Intervals: given intervals, merge all overlapping intervals
// Time Complexity: O(n log n)
// Space Complexity: O(n) for output

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }
    return res;
}

int main()
{
    vector<vector<int>> a1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto r1 = mergeIntervals(a1);
    for (auto& iv : r1) cout << "{" << iv[0] << "," << iv[1] << "} ";
    cout << "\n";  // {1,6} {8,10} {15,18}
    vector<vector<int>> a2 = {{1, 4}, {4, 5}};
    auto r2 = mergeIntervals(a2);
    for (auto& iv : r2) cout << "{" << iv[0] << "," << iv[1] << "} ";
    cout << "\n";  // {1,5}
    return 0;
}
