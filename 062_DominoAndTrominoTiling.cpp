// Topic: Dynamic Programming
// Domino and Tromino Tiling (LeetCode 790): count tilings using recurrence with mod
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int numTilings(int n)
{
    const int MOD = 1e9 + 7;
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    long long a = 1;  // dp[0]
    long long b = 1;  // dp[1]
    long long c = 2;  // dp[2]
    if (n == 2)
        return (int)c;
    for (int i = 3; i <= n; i++)
    {
        long long d = ((2 * c % MOD) + a) % MOD;
        a = b;
        b = c;
        c = d;
    }
    return (int)c;
}

int main()
{
    cout << numTilings(3) << "\n";  // 5
    cout << numTilings(4) << "\n";  // 11
    return 0;
}
