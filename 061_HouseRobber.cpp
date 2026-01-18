// Topic: Dynamic Programming
// House Robber: maximize sum of non-adjacent houses using O(1) space DP
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums)
{
    int incl = 0, excl = 0;
    for (int x : nums)
    {
        int new_excl = max(incl, excl);
        incl = excl + x;
        excl = new_excl;
    }
    return max(incl, excl);
}

int main()
{
    cout << rob((vector<int>{1, 2, 3, 1})) << "\n";     // 4
    cout << rob((vector<int>{2, 7, 9, 3, 1})) << "\n";  // 12
    return 0;
}
