// Topic: Greedy / Interval Cover
// Minimum Number of Taps to Open to Water a Garden: convert ranges and greedily jump.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int>& ranges)
{
    vector<int> maxReach(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);
        maxReach[left] = max(maxReach[left], right);
    }
    int taps = 0, curEnd = 0, nextEnd = 0;
    for (int i = 0; i <= n; i++)
    {
        nextEnd = max(nextEnd, maxReach[i]);
        if (i == curEnd)
        {
            if (nextEnd <= i)
                return -1;
            taps++;
            curEnd = nextEnd;
            if (curEnd >= n)
                break;
        }
    }
    return taps;
}

int main()
{
    cout << minTaps(5, (vector<int>{3, 4, 1, 1, 0, 0})) << "\n";  // 1
    cout << minTaps(3, (vector<int>{0, 0, 0, 0})) << "\n";        // -1
    return 0;
}
