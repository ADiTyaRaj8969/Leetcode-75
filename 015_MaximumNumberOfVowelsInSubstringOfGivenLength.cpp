// Topic: Sliding Window / String
// Maximum Number of Vowels in Substring of Given Length: Find the most vowels in any substring of
// length k. Time Complexity: O(n) Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(const string& s, int k)
{
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < min(n, k); ++i)
        if (isVowel(s[i]))
            ++cnt;
    int best = cnt;
    for (int i = k; i < n; ++i)
    {
        if (isVowel(s[i - k]))
            --cnt;
        if (isVowel(s[i]))
            ++cnt;
        best = max(best, cnt);
    }
    return best;
}

int main()
{
    cout << maxVowels("abciiidef", 3) << '\n';  // 3
    cout << maxVowels("aeiou", 2) << '\n';      // 2
    cout << maxVowels("leetcode", 3) << '\n';   // 2
    return 0;
}
