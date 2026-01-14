// Topic: String / Stack
// Removing Stars From a String: Remove characters from a string as if '*' deletes the previous
// character. Time Complexity: O(n) Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

string removeStars(const string& s)
{
    string res;
    res.reserve(s.size());
    for (char c : s)
    {
        if (c == '*')
        {
            if (!res.empty())
                res.pop_back();
        }
        else
            res.push_back(c);
    }
    return res;
}

int main()
{
    cout << removeStars("leet**cod*e") << '\n';  // lecoe
    cout << removeStars("erase*****") << '\n';   // (empty)
    cout << removeStars("ab*c") << '\n';         // ac
    return 0;
}
