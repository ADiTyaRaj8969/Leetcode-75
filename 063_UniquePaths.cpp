// Topic: Combinatorics / DP
// Unique Paths: count lattice paths from top-left to bottom-right
// Time Complexity: O(min(m,n)) if using multiplicative formula
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

long long uniquePaths(int m, int n)
{
    int k = min(m - 1, n - 1);
    long double res = 1;
    for (int i = 1; i <= k; i++)
    {
        res = res * (m + n - 2 - k + i) / i;
    }
    return (long long)(res + 0.5L);
}

int main()
{
    cout << uniquePaths(3, 7) << "\n";  // 28
    cout << uniquePaths(3, 2) << "\n";  // 3
    return 0;
}
