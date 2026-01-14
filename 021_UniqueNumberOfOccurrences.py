"""
Topic: Hashmap / Set
Unique Number of Occurrences: check if frequency counts are unique
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import Counter

def unique_occurrences(arr):
    cnt = Counter(arr)
    occ = list(cnt.values())
    return len(occ) == len(set(occ))


if __name__ == '__main__':
    print(unique_occurrences([1,2,2,1,1,3]))  # True (counts: 1->3,2->2,3->1)
    print(unique_occurrences([1,2]))  # False