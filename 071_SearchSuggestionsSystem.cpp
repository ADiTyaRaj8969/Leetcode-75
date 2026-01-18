// Topic: Sorting / Binary Search
// Search Suggestions System: given products and a search word, return up to 3 lexicographically
// smallest products for each prefix Approach: sort products, for each prefix binary search
// lower_bound and pick up to 3 matches Time Complexity: O(n log n + m log n + m * k) where m =
// length of searchWord, k=3 Space Complexity: O(1) extra (excluding output)

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    string prefix;
    for (char c : searchWord)
    {
        prefix.push_back(c);
        auto it = lower_bound(products.begin(), products.end(), prefix);
        vector<string> bucket;
        for (int k = 0; k < 3 && it + k < products.end(); ++k)
        {
            const string& s = *(it + k);
            if (s.size() >= prefix.size() && s.compare(0, prefix.size(), prefix) == 0)
                bucket.push_back(s);
            else
                break;
        }
        res.push_back(bucket);
    }
    return res;
}

int main()
{
    vector<string> p1 = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    auto r1 = suggestedProducts(p1, "mouse");
    for (auto& v : r1)
    {
        for (auto& s : v) cout << s << " ";
        cout << "\n";
    }
    cout << "---\n";
    vector<string> p2 = {"havana"};
    auto r2 = suggestedProducts(p2, "havana");
    for (auto& v : r2)
    {
        for (auto& s : v) cout << s << " ";
        cout << "\n";
    }
    return 0;
}
