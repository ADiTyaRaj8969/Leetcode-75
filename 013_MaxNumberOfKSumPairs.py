"""
Topic: Hashmap / Two Sum Variant
Max Number of K-Sum Pairs: greedy with counts
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import Counter

def max_operations(nums, k):
    cnt = Counter(nums)
    res = 0
    for x in list(cnt.keys()):
        while cnt[x] > 0:
            need = k - x
            if need not in cnt or cnt[need] == 0:
                break
            if need == x:
                pairs = cnt[x] // 2
                res += pairs
                cnt[x] -= pairs * 2
                break
            else:
                use = min(cnt[x], cnt[need])
                res += use
                cnt[x] -= use
                cnt[need] -= use
                break
    return res


if __name__ == '__main__':
    print(max_operations([1,2,3,4], 5))  # 2 (1+4,2+3)
    print(max_operations([3,1,3,4,3], 6))  # 1 (3+3)
