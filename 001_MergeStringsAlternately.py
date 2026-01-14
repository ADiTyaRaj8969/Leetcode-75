"""
Topic: Two Pointers / String
Merge Strings Alternately: merge characters from two strings alternately
Time Complexity: O(n + m)
Space Complexity: O(n + m)
"""

def merge_alternately(a: str, b: str) -> str:
    i = j = 0
    res = []
    turn = 0
    while i < len(a) or j < len(b):
        if turn == 0 and i < len(a):
            res.append(a[i]); i += 1
        elif turn == 1 and j < len(b):
            res.append(b[j]); j += 1
        else:
            # if current string exhausted, append from the other
            if i < len(a): res.append(a[i]); i += 1
            elif j < len(b): res.append(b[j]); j += 1
        turn ^= 1
    return ''.join(res)


if __name__ == '__main__':
    print(merge_alternately('abc', 'pqr'))  # apbqcr
    print(merge_alternately('ab', 'pqrs'))  # apbqrs
    print(merge_alternately('', 'xyz'))     # xyz
