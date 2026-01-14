// Topic: String / Two pointers
// Reverse Words in a String: Reverse the order of words in a sentence, trimming whitespace.
// Time Complexity: O(n)
// Space Complexity: O(n) for storing words

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    int n = s.size();
    for (int i = 0; i < n;)
    {
        while (i < n && isspace((unsigned char)s[i])) ++i;
        if (i >= n)
            break;
        int j = i;
        while (j < n && !isspace((unsigned char)s[j])) ++j;
        words.emplace_back(s.substr(i, j - i));
        i = j;
    }
    reverse(words.begin(), words.end());
    string out;
    for (size_t i = 0; i < words.size(); ++i)
    {
        if (i)
            out.push_back(' ');
        out += words[i];
    }
    return out;
}

int main()
{
    cout << '"' << reverseWords("  the sky   is blue  ") << '"' << '\n';  // "blue is sky the"
    cout << '"' << reverseWords("hello world") << '"' << '\n';            // "world hello"
    cout << '"' << reverseWords("a good   example") << '"' << '\n';       // "example good a"
    return 0;
}
