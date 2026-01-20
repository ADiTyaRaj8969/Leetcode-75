"""
Topic: Two Pointers / In-place Simulation
String Compression: compress consecutive chars counts, return new length or compressed string
Time Complexity: O(n)
Space Complexity: O(n) (for returned string)
"""

def compress(chars: str) -> str:
    if not chars:
        return ''
    res = []
    i = 0
    n = len(chars)
    while i < n:
        j = i
        while j < n and chars[j] == chars[i]:
            j += 1
        count = j - i
        res.append(chars[i])
        if count > 1:
            res.append(str(count))
        i = j
    return ''.join(res)


if __name__ == '__main__':
    print(compress('aabbccc'))  # a2b2c3
    print(compress('a'))        # a
