// Topic: HashSet / Union-Find
// Longest Consecutive Sequence: use unordered_set to expand ranges in O(n)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : nums)
    {
        if (!s.count(x - 1))
        {
            int cur = x, len = 1;
            while (s.count(cur + 1))
            {
                cur++;
                len++;
            }
            best = max(best, len);
        }
    }
    return best;
}

int main()
{
    cout << longestConsecutive((vector<int>{100, 4, 200, 1, 3, 2})) << "\n";  // 4
    cout << longestConsecutive((vector<int>{})) << "\n";                      // 0
    return 0;
}
