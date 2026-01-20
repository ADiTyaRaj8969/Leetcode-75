// Topic: Hashmap / Greedy
// Max Number of K-Sum Pairs: Find the maximum number of pairs in an array that sum to k.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k)
{
    unordered_map<int, int> cnt;
    int ops = 0;
    for (int x : nums)
    {
        int need = k - x;
        auto it = cnt.find(need);
        if (it != cnt.end() && it->second > 0)
        {
            --(it->second);
            ++ops;
        }
        else
        {
            ++cnt[x];
        }
    }
    return ops;
}

int main()
{
    vector<int> a1 = {1, 2, 3, 4};
    cout << maxOperations(a1, 5) << '\n';  // 2
    vector<int> a2 = {3, 1, 3, 4, 3};
    cout << maxOperations(a2, 6) << '\n';  // 1
    vector<int> a3 = {3, 3, 3, 3};
    cout << maxOperations(a3, 6) << '\n';  // 2
    return 0;
}
