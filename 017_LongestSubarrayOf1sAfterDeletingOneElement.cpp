// Topic: Sliding Window / Two pointers
// Longest Subarray of 1's After Deleting One Element: Find the longest subarray after removing
// exactly one element. Time Complexity: O(n) Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums)
{
    int left = 0, zeros = 0, best = 0;
    for (int right = 0; right < (int)nums.size(); ++right)
    {
        if (nums[right] == 0)
            ++zeros;
        while (zeros > 1)
        {
            if (nums[left] == 0)
                --zeros;
            ++left;
        }
        // length after deleting one element = window size - 1
        best = max(best, right - left);
    }
    return best;
}

int main()
{
    vector<int> a1 = {1, 1, 0, 1};
    cout << longestSubarray(a1) << '\n';  // 3
    vector<int> a2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << longestSubarray(a2) << '\n';  // 5
    vector<int> a3 = {1, 1, 1};
    cout << longestSubarray(a3) << '\n';  // 2 (must delete one)
    return 0;
}
