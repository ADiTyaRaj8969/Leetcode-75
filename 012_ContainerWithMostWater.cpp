// Topic: Two Pointers / Greedy
// Container With Most Water: Find two lines that, with the x-axis, hold the most water.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxArea(const vector<int>& height)
{
    int l = 0, r = (int)height.size() - 1;
    long long best = 0;
    while (l < r)
    {
        long long h = min(height[l], height[r]);
        best = max(best, h * (r - l));
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return (int)best;
}

int main()
{
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << '\n';  // 49
    cout << maxArea({1, 1}) << '\n';                       // 1
    cout << maxArea({4, 3, 2, 1, 4}) << '\n';              // 16
    return 0;
}
