// Topic: Dynamic Programming
// Longest Common Subsequence: classic 2D DP O(m*n)
// Time Complexity: O(m*n)
// Space Complexity: O(min(m,n)) optimized

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    if (text1.size() < text2.size())
        swap(text1, text2);
    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0);
    for (int i = m - 1; i >= 0; --i)
    {
        vector<int> ndp(n + 1, 0);
        for (int j = n - 1; j >= 0; --j)
        {
            if (text1[i] == text2[j])
                ndp[j] = 1 + dp[j + 1];
            else
                ndp[j] = max(dp[j], ndp[j + 1]);
        }
        dp.swap(ndp);
    }
    return dp[0];
}

int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << "\n";  // 3
    cout << longestCommonSubsequence("abc", "abc") << "\n";    // 3
    return 0;
}
