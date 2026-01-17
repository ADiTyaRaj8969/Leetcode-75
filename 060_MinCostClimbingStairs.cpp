// Topic: Dynamic Programming
// Min Cost Climbing Stairs: dp with O(1) space keeping last two costs
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    int a = 0, b = 0;  // cost to reach i-2 and i-1
    for (int i = 2; i <= n; i++)
    {
        int takeOne = b + cost[i - 1];
        int takeTwo = a + cost[i - 2];
        int cur = min(takeOne, takeTwo);
        a = b;
        b = cur;
    }
    return b;
}

int main()
{
    cout << minCostClimbingStairs((vector<int>{10, 15, 20})) << "\n";                          // 15
    cout << minCostClimbingStairs((vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1})) << "\n";  // 6
    return 0;
}
