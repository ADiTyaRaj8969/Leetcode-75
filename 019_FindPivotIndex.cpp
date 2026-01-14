// Topic: Prefix Sums / Array
// Find Pivot Index: Find an array index where the sum of numbers to its left equals the right.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(const vector<int>& nums)
{
    long long total = 0;
    for (int x : nums) total += x;
    long long left = 0;
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        if (left == total - left - nums[i])
            return i;
        left += nums[i];
    }
    return -1;
}

int main()
{
    cout << pivotIndex({1, 7, 3, 6, 5, 6}) << '\n';  // 3
    cout << pivotIndex({1, 2, 3}) << '\n';           // -1
    cout << pivotIndex({2, 1, -1}) << '\n';          // 0
    return 0;
}
