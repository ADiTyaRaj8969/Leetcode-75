// Topic: Heap / Greedy
// Minimum Cost to Connect Sticks: repeatedly connect two smallest sticks; cost is sum.
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

long long connectSticks(vector<int>& sticks)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq(sticks.begin(),
                                                                        sticks.end());
    long long cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{
    cout << connectSticks((vector<int>{2, 4, 3})) << "\n";     // 14
    cout << connectSticks((vector<int>{1, 8, 3, 5})) << "\n";  // 30
    return 0;
}
