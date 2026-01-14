// Topic: String / Math (GCD)
// Greatest Common Divisor of Strings: Find the largest string that evenly divides two given
// strings. Time Complexity: O(n) where n = min(len1, len2) for checking, overall O(len1 + len2)
// Space Complexity: O(n) for candidate substring

#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(const string& str1, const string& str2)
{
    if (str1 + str2 != str2 + str1)
        return "";
    int a = str1.size(), b = str2.size();
    int g = std::gcd(a, b);
    return str1.substr(0, g);
}

int main()
{
    cout << gcdOfStrings("ABCABC", "ABC") << "\n";   // ABC
    cout << gcdOfStrings("ABABAB", "ABAB") << "\n";  // AB
    cout << (gcdOfStrings("LEET", "CODE").empty() ? string("") : gcdOfStrings("LEET", "CODE"))
         << "\n";  // (empty)
    return 0;
}
