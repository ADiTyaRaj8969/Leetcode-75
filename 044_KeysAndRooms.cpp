// Topic: Graph / DFS
// Keys and Rooms: Determine if all rooms can be visited starting from room 0.
// Time Complexity: O(n + e)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    int n = rooms.size();
    vector<char> vis(n, 0);
    stack<int> st;
    st.push(0);
    vis[0] = 1;
    int cnt = 1;
    while (!st.empty())
    {
        int r = st.top();
        st.pop();
        for (int k : rooms[r])
            if (!vis[k])
            {
                vis[k] = 1;
                st.push(k);
                ++cnt;
            }
    }
    return cnt == n;
}

int main()
{
    vector<vector<int>> r1 = {{1}, {2}, {3}, {}};
    cout << (canVisitAllRooms(r1) ? "true" : "false") << '\n';  // true
    vector<vector<int>> r2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << (canVisitAllRooms(r2) ? "true" : "false") << '\n';  // false
    return 0;
}
