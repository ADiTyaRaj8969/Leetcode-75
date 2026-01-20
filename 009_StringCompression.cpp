// Topic: String / Two pointers
// String Compression: Compress a string of characters by counting consecutive repeats (e.g.,
// "aabbb" -> "a2b3"). This implementation returns the compressed string (not in-place), which is
// simple and clear. Time Complexity: O(n) Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

string compressString(const string& s)
{
    if (s.empty())
        return s;
    string out;
    out.reserve(s.size());
    int n = s.size();
    for (int i = 0; i < n;)
    {
        char c = s[i];
        int j = i + 1;
        while (j < n && s[j] == c) ++j;
        out.push_back(c);
        int cnt = j - i;
        if (cnt > 1)
            out += to_string(cnt);
        i = j;
    }
    return out;
}

int main()
{
    cout << compressString("aabcccccaaa") << '\n';  // a2bc5a3
    cout << compressString("abcd") << '\n';         // abcd
    cout << compressString("") << '\n';             // (empty)
    return 0;
}
