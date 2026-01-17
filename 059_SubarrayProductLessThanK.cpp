// Topic: Sliding Window / Two Pointers
// Subarray Product Less Than K: use sliding window maintaining product
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    if (k <= 1)
        return 0;
    long long prod = 1;
    int left = 0, res = 0;
    for (int right = 0; right < nums.size(); ++right)
    {
        prod *= nums[right];
        while (prod >= k)
        {
            prod /= nums[left++];
        }
        res += right - left + 1;
    }
    return res;
}

int main()
{
    cout << numSubarrayProductLessThanK((vector<int>{10, 5, 2, 6}), 100) << "\n";  // 8
    cout << numSubarrayProductLessThanK((vector<int>{1, 2, 3}), 0) << "\n";        // 0
    return 0;
}
