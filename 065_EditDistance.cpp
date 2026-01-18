// Topic: Dynamic Programming
// Edit Distance: classic Levenshtein distance (insert/delete/replace)
// Time Complexity: O(m*n)
// Space Complexity: O(min(m,n)) optimized

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    if (word1.size() < word2.size())
        swap(word1, word2);
    int m = word1.size(), n = word2.size();
    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= m; i++)
    {
        vector<int> ndp(n + 1);
        ndp[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                ndp[j] = dp[j - 1];
            else
                ndp[j] = 1 + min({dp[j], ndp[j - 1], dp[j - 1]});
        }
        dp.swap(ndp);
    }
    return dp[n];
}

int main()
{
    cout << minDistance("horse", "ros") << "\n";            // 3
    cout << minDistance("intention", "execution") << "\n";  // 5
    return 0;
}
