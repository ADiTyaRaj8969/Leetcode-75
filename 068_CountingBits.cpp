// Topic: Dynamic Programming / Bit Tricks
// Counting Bits: compute number of set bits for all numbers 0..n using dp relation
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) res[i] = res[i & (i - 1)] + 1;
    return res;
}

int main()
{
    auto r = countBits(5);
    for (int x : r) cout << x << " ";
    cout << "\n";  // 0 1 1 2 1 2
    r = countBits(0);
    for (int x : r) cout << x << " ";
    cout << "\n";  // 0
    return 0;
}
