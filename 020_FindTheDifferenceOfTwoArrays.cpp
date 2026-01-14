// Topic: Hash Set / Arrays
// Find the Difference of Two Arrays: Return two lists: distinct elements only in the first array,
// and only in the second. Time Complexity: O(n + m) Space Complexity: O(n + m)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(const vector<int>& nums1, const vector<int>& nums2)
{
    unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
    vector<int> a, b;
    for (int x : s1)
        if (s2.find(x) == s2.end())
            a.push_back(x);
    for (int x : s2)
        if (s1.find(x) == s1.end())
            b.push_back(x);
    return {a, b};
}

int main()
{
    auto res1 = findDifference({1, 2, 3}, {2, 4, 6});
    for (auto x : res1[0]) cout << x << ' ';
    cout << "\n";  // 1 3 (order may vary)
    for (auto x : res1[1]) cout << x << ' ';
    cout << "\n";  // 4 6 (order may vary)

    auto res2 = findDifference({1, 2, 3, 3}, {1, 1, 2, 2});
    for (auto x : res2[0]) cout << x << ' ';
    cout << "\n";  // 3
    for (auto x : res2[1]) cout << x << ' ';
    cout << "\n";  // (empty)

    return 0;
}
