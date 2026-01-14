// Topic: Array / Greedy
// Kids With the Greatest Number of Candies: Check if each kid can have the most candies after
// receiving extras. Time Complexity: O(n) Space Complexity: O(n) for result

#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(const vector<int>& candies, int extra)
{
    int mx = *max_element(candies.begin(), candies.end());
    vector<bool> ans;
    ans.reserve(candies.size());
    for (int c : candies) ans.push_back(c + extra >= mx);
    return ans;
}

int main()
{
    auto print = [](const vector<bool>& v)
    {
        for (bool b : v) cout << (b ? "true" : "false") << ' ';
        cout << '\n';
    };
    print(kidsWithCandies({2, 3, 5, 1, 3}, 3));  // true true true false true
    print(kidsWithCandies({4, 2, 1, 1, 2}, 1));  // true false false false false
    print(kidsWithCandies({12, 1, 12}, 10));     // true false true
    return 0;
}
