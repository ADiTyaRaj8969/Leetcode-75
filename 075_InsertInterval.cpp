// Topic: Intervals / Insertion
// Insert Interval: insert a new interval and merge overlapping intervals
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int> newInterval)
{
    vector<vector<int>> res;
    int i = 0, n = intervals.size();
    while (i < n && intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < n) res.push_back(intervals[i++]);
    return res;
}

int main()
{
    vector<vector<int>> a1 = {{1, 3}, {6, 9}};
    auto r1 = insertInterval(a1, {2, 5});
    for (auto& iv : r1) cout << "{" << iv[0] << "," << iv[1] << "} ";
    cout << "\n";  // {1,5} {6,9}
    vector<vector<int>> a2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    auto r2 = insertInterval(a2, {4, 8});
    for (auto& iv : r2) cout << "{" << iv[0] << "," << iv[1] << "} ";
    cout << "\n";  // {1,2} {3,10} {12,16}
    return 0;
}
