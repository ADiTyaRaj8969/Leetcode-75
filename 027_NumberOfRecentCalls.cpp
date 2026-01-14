// Topic: Queue / Class
// Number of Recent Calls: Count pings that occurred in the last 3000 milliseconds.
// Time Complexity: O(1) amortized per ping
// Space Complexity: O(n) for stored pings

#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
   public:
    deque<int> q;
    RecentCounter() {}
    int ping(int t)
    {
        q.push_back(t);
        while (!q.empty() && q.front() < t - 3000) q.pop_front();
        return q.size();
    }
};

int main()
{
    RecentCounter rc;
    cout << rc.ping(1) << '\n';     // 1
    cout << rc.ping(100) << '\n';   // 2
    cout << rc.ping(3001) << '\n';  // 3
    cout << rc.ping(3002) << '\n';  // 3
    cout << rc.ping(7000) << '\n';  // 1
    return 0;
}
