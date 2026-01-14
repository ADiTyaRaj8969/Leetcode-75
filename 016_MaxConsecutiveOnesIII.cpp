// Topic: Sliding Window / Two pointers
// Max Consecutive Ones III: Find the longest subarray of 1s, allowing you to flip at most k zeros.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k)
{
    int left = 0, zeros = 0, best = 0;
    for (int right = 0; right < (int)nums.size(); ++right)
    {
        if (nums[right] == 0)
            ++zeros;
        while (zeros > k)
        {
            if (nums[left] == 0)
                --zeros;
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main()
{
    vector<int> a1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << longestOnes(a1, 2) << '\n';  // 6
    vector<int> a2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestOnes(a2, 3) << '\n';
    vector<int> a3 = {1, 0, 0, 1, 1, 0, 1};
    cout << longestOnes(a3, 1) << '\n';
    return 0;
}
