// Topic: Greedy / Array
// Increasing Triplet Subsequence: Find if three numbers in increasing order exist in an array.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(const vector<int>& nums)
{
    int first = INT_MAX, second = INT_MAX;
    for (int x : nums)
    {
        if (x <= first)
            first = x;
        else if (x <= second)
            second = x;
        else
            return true;
    }
    return false;
}

int main()
{
    cout << (increasingTriplet({1, 2, 3, 4, 5}) ? "true" : "false") << '\n';     // true
    cout << (increasingTriplet({5, 4, 3, 2, 1}) ? "true" : "false") << '\n';     // false
    cout << (increasingTriplet({2, 1, 5, 0, 4, 6}) ? "true" : "false") << '\n';  // true (1,4,6)
    return 0;
}
