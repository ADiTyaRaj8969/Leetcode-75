// Topic: Sliding Window / Hashmap
// Minimum Window Substring: standard sliding window to cover all chars of t in s.
// Time Complexity: O(|S| + |T|)
// Space Complexity: O(1) assuming ascii / O(|T|)

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (t.empty())
        return "";
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int missing = t.size();
    int left = 0, minLen = INT_MAX, start = 0;
    for (int right = 0; right < s.size(); ++right)
    {
        if (need[s[right]] > 0)
            missing--;
        need[s[right]]--;
        while (missing == 0)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }
            need[s[left]]++;
            if (need[s[left]] > 0)
                missing++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";  // BANC
    cout << minWindow("a", "aa") << "\n";               // ""
    return 0;
}
