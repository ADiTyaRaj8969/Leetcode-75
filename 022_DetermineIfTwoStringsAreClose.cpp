// Topic: String / Hashing
// Determine if Two Strings Are Close: Two strings are "close" if you can transform one to the other
// using any number of operations: swap any two characters, or transform all occurrences of one
// character into another existing character. Equivalent check: same character set and same
// multiset of frequencies.
// Time Complexity: O(n + k log k) where k = alphabet size (<=26)
// Space Complexity: O(k)

#include <bits/stdc++.h>
using namespace std;

bool closeStrings(const string& w1, const string& w2)
{
    if (w1.size() != w2.size())
        return false;
    array<int, 26> f1{};
    array<int, 26> f2{};
    for (char c : w1) ++f1[c - 'a'];
    for (char c : w2) ++f2[c - 'a'];
    for (int i = 0; i < 26; ++i)
        if ((f1[i] > 0) != (f2[i] > 0))
            return false;
    vector<int> a, b;
    for (int i = 0; i < 26; ++i)
        if (f1[i])
            a.push_back(f1[i]);
    for (int i = 0; i < 26; ++i)
        if (f2[i])
            b.push_back(f2[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main()
{
    cout << (closeStrings("abc", "bca") ? "true" : "false") << '\n';          // true
    cout << (closeStrings("a", "aa") ? "true" : "false") << '\n';             // false
    cout << (closeStrings("abbzccc", "bcccazz") ? "true" : "false") << '\n';  // true
    return 0;
}
