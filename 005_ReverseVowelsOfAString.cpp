// Topic: Two Pointers / String
// Reverse Vowels of a String: Reverse only the vowel characters within a given string.
// Time Complexity: O(n)
// Space Complexity: O(1) extra (in-place)

#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s)
{
    auto isv = [](char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int i = 0, j = (int)s.size() - 1;
    while (i < j)
    {
        while (i < j && !isv(s[i])) ++i;
        while (i < j && !isv(s[j])) --j;
        if (i < j)
            swap(s[i++], s[j--]);
    }
    return s;
}

int main()
{
    cout << reverseVowels("hello") << '\n';     // holle
    cout << reverseVowels("leetcode") << '\n';  // leotcede
    cout << reverseVowels("aA") << '\n';        // Aa
    return 0;
}
