// Topic: Prefix Sum / Array
// Find the Highest Altitude: Calculate the highest altitude reached during a hike, given gains and
// losses. Time Complexity: O(n) Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int largestAltitude(const vector<int>& gain)
{
    int alt = 0, best = 0;
    for (int g : gain)
    {
        alt += g;
        best = max(best, alt);
    }
    return best;
}

int main()
{
    cout << largestAltitude({-5, 1, 5, 0, -7}) << '\n';  // 1
    cout << largestAltitude({-4, -3, -2, -1, 4, 3, 2}) << '\n';
    cout << largestAltitude({0, 0, 0}) << '\n';
    return 0;
}
