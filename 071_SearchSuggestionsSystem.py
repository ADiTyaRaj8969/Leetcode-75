"""
Topic: Trie / Sorting
Problem: Search Suggestions System
Description: Given products and a search word, return at most 3 suggestions after each character typed.
Time: O(n log n + L * log n) where L is search word length
Space: O(n * avg_len)
"""

from typing import List


def suggestedProducts(products: List[str], searchWord: str) -> List[List[str]]:
    products.sort()
    res = []
    prefix = ""
    for ch in searchWord:
        prefix += ch
        # binary search left bound
        l = 0
        r = len(products)
        while l < r:
            m = (l + r) // 2
            if products[m] < prefix:
                l = m + 1
            else:
                r = m
        # collect up to 3 starting from l
        suggestions = []
        for i in range(l, min(l+3, len(products))):
            if products[i].startswith(prefix):
                suggestions.append(products[i])
            else:
                break
        res.append(suggestions)
    return res


if __name__ == '__main__':
    print(suggestedProducts(["mobile","mouse","moneypot","monitor","mousepad"], "mouse"))
    print(suggestedProducts(["huawei","honey","honest"], "ho"))
