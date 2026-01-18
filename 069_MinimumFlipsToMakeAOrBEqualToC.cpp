// Topic: Bit Manipulation
// Minimum Flips to Make A OR B Equal to C: for each bit compute minimal flips
// Time Complexity: O(1) per number (bits up to 31) -> O(1)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int minFlips(int a, int b, int c)
{
    int flips = 0;
    for (int i = 0; i < 31; i++)
    {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;
        if (bitC == 0)
        {
            flips += bitA + bitB;
        }
        else
        {
            if ((bitA | bitB) == 0)
                flips += 1;
        }
    }
    return flips;
}

int main()
{
    cout << minFlips(2, 6, 5) << "\n";  // 3
    cout << minFlips(4, 2, 7) << "\n";  // 1
    return 0;
}
