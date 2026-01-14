// Topic: Hashmap / Set
// Unique Number of Occurrences: Check if the frequency of each number in an array is unique.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(const vector<int>& arr)
{
    unordered_map<int, int> freq;
    for (int x : arr) ++freq[x];
    unordered_set<int> seen;
    for (auto& p : freq)
    {
        if (!seen.insert(p.second).second)
            return false;
    }
    return true;
}

int main()
{
    cout << (uniqueOccurrences({1, 2, 2, 1, 1, 3}) ? "true" : "false") << '\n';  // true
    cout << (uniqueOccurrences({1, 2}) ? "true" : "false") << '\n';              // false
    cout << (uniqueOccurrences({-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}) ? "true" : "false")
         << '\n';  // true
    return 0;
}
