// Topic: Dynamic Programming / Greedy
// Best Time to Buy and Sell Stock with Transaction Fee: maintain hold and cash states
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee)
{
    long long hold = -prices[0], cash = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return (int)cash;
}

int main()
{
    cout << maxProfit((vector<int>{1, 3, 2, 8, 4, 9}), 2) << "\n";   // 8
    cout << maxProfit((vector<int>{1, 3, 7, 5, 10, 3}), 3) << "\n";  // 6
    return 0;
}
