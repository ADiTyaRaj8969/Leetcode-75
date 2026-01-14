// Topic: Sliding Window / Array
// Maximum Average Subarray I: Find the highest average of all contiguous subarrays of fixed length
// k. Time Complexity: O(n) Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(const vector<int>& nums, int k)
{
    long long sum = 0;
    for (int i = 0; i < k; ++i) sum += nums[i];
    long long best = sum;
    for (int i = k; i < (int)nums.size(); ++i)
    {
        sum += nums[i];
        sum -= nums[i - k];
        best = max(best, sum);
    }
    return (double)best / k;
}

int main()
{
    cout << fixed << setprecision(6) << findMaxAverage({1, 12, -5, -6, 50, 3}, 4) << '\n';  // 12.75
    cout << fixed << setprecision(6) << findMaxAverage({5}, 1) << '\n';                     // 5.0
    cout << fixed << setprecision(6) << findMaxAverage({0, 1, 1, 3, 3}, 4) << '\n';
    return 0;
}
