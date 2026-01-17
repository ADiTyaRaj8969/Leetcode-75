// Topic: Heap / Greedy
// Total Cost to Hire K Workers: choose k workers with minimal cost using two pools and candidates
// window. Time Complexity: O(k log n) Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates)
{
    int n = costs.size();
    long long ans = 0;
    int l = 0, r = n - 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leftPQ, rightPQ;
    while (k--)
    {
        while ((int)leftPQ.size() < candidates && l <= r) leftPQ.push({costs[l], l++});
        while ((int)rightPQ.size() < candidates && l <= r) rightPQ.push({costs[r], r--});
        if (leftPQ.empty())
        {
            ans += rightPQ.top().first;
            rightPQ.pop();
        }
        else if (rightPQ.empty())
        {
            ans += leftPQ.top().first;
            leftPQ.pop();
        }
        else
        {
            if (leftPQ.top() <= rightPQ.top())
            {
                ans += leftPQ.top().first;
                leftPQ.pop();
            }
            else
            {
                ans += rightPQ.top().first;
                rightPQ.pop();
            }
        }
    }
    return ans;
}

int main()
{
    cout << totalCost((vector<int>{17, 12, 10, 2, 7, 2, 11, 20, 8}), 3, 4) << "\n";  // 11
    cout << totalCost((vector<int>{1, 2, 4, 1}), 3, 3) << "\n";                      // 4
    return 0;
}
