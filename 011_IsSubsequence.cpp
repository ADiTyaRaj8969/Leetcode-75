// Topic: Two Pointers / String
// Is Subsequence: Check if one string can be formed by deleting characters from another string.
// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(const string& s, const string& t)
{
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size())
    {
        if (s[i] == t[j])
            ++i;
        ++j;
    }
    return i == (int)s.size();
}

int main()
{
    cout << (isSubsequence("abc", "ahbgdc") ? "true" : "false") << '\n';  // true
    cout << (isSubsequence("axc", "ahbgdc") ? "true" : "false") << '\n';  // false
    cout << (isSubsequence("", "ahbgdc") ? "true" : "false") << '\n';     // true
    return 0;
}
