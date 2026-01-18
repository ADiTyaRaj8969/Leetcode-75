"""
Topic: Dynamic Programming / Greedy
Problem: Best Time to Buy and Sell Stock with Transaction Fee
Description: Track hold and cash states to maximize profit.
Time: O(n)
Space: O(1)
"""

from typing import List


def maxProfit(prices: List[int], fee: int) -> int:
    cash, hold = 0, -prices[0]
    for p in prices[1:]:
        cash = max(cash, hold + p - fee)
        hold = max(hold, cash - p)
    return cash


if __name__ == '__main__':
    print(maxProfit([1,3,2,8,4,9], 2))  # 8
    print(maxProfit([1,3,7,5,10,3], 3))  # 6
