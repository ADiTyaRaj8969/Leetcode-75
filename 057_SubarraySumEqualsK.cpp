// Topic: Hashmap / Prefix Sum
// Subarray Sum Equals K: count subarrays with sum equal to k using prefix sums and hashmap.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0, res = 0;
    for (int x : nums)
    {
        sum += x;
        if (cnt.count(sum - k))
            res += cnt[sum - k];
        cnt[sum]++;
    }
    return res;
}

int main()
{
    cout << subarraySum((vector<int>{1, 1, 1}), 2) << "\n";  // 2
    cout << subarraySum((vector<int>{1, 2, 3}), 3) << "\n";  // 2
    return 0;
}
