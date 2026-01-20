// Topic: Array / Prefix & Suffix products
// Product of Array Except Self: Create a new array where each element is the product of all others.
// Time Complexity: O(n)
// Space Complexity: O(1) extra (output array not counted)

#include <bits/stdc++.h>
using namespace std;

vector<long long> productExceptSelf(const vector<int>& nums)
{
    int n = nums.size();
    vector<long long> res(n, 1);
    long long left = 1;
    for (int i = 0; i < n; ++i)
    {
        res[i] = left;
        left *= nums[i];
    }
    long long right = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}

int main()
{
    auto print = [](const vector<long long>& v)
    {
        for (auto x : v) cout << x << ' ';
        cout << "\n";
    };
    print(productExceptSelf({1, 2, 3, 4}));       // 24 12 8 6
    print(productExceptSelf({-1, 1, 0, -3, 3}));  // 0 0 9 0 0
    return 0;
}
