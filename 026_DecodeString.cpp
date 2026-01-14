// Topic: Stack / String
// Decode String: Decode strings encoded with counts and brackets like "3[a]2[bc]" -> "aaabcbc".
// Time Complexity: O(n * k) where k from repeats (output length)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

string decodeString(const string& s)
{
    stack<int> counts;
    stack<string> strs;
    string cur;
    int k = 0;
    for (char ch : s)
    {
        if (isdigit(ch))
            k = k * 10 + (ch - '0');
        else if (ch == '[')
        {
            counts.push(k);
            k = 0;
            strs.push(cur);
            cur.clear();
        }
        else if (ch == ']')
        {
            int cnt = counts.top();
            counts.pop();
            string prev = strs.top();
            strs.pop();
            string tmp;
            tmp.reserve(prev.size() + cur.size() * cnt);
            tmp += prev;
            for (int i = 0; i < cnt; ++i) tmp += cur;
            cur.swap(tmp);
        }
        else
            cur.push_back(ch);
    }
    return cur;
}

int main()
{
    cout << decodeString("3[a]2[bc]") << '\n';      // aaabcbc
    cout << decodeString("3[a2[c]]") << '\n';       // accaccacc
    cout << decodeString("2[abc]3[cd]ef") << '\n';  // abcabccdcdcdef
    return 0;
}
