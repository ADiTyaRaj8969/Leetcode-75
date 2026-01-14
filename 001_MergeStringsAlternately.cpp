// Topic: Two Pointers / String
// Merge Strings Alternately: Combine two strings by adding letters in alternating order.
// Time Complexity: O(n) where n = s1.size() + s2.size()
// Space Complexity: O(n) for the resulting string

#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(const string& s1, const string& s2)
{
    string res;
    res.reserve(s1.size() + s2.size());
    size_t i = 0, j = 0;
    while (i < s1.size() || j < s2.size())
    {
        if (i < s1.size())
            res.push_back(s1[i++]);
        if (j < s2.size())
            res.push_back(s2[j++]);
    }
    return res;
}

int main()
{
    cout << mergeAlternately("abc", "pqr") << "\n";  // apbqcr
    cout << mergeAlternately("ab", "pqrs") << "\n";  // apbqrs
    cout << mergeAlternately("abcd", "pq") << "\n";  // apbqcd
    return 0;
}
