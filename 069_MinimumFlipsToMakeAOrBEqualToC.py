"""
Topic: Bit Manipulation
Problem: Minimum Flips to Make A OR B Equal to C
Description: Count bit flips required to make (a|b)==c.
Time: O(1) per bit, O(32) overall
Space: O(1)
"""

def minFlips(a: int, b: int, c: int) -> int:
    flips = 0
    for i in range(32):
        bitA = (a >> i) & 1
        bitB = (b >> i) & 1
        bitC = (c >> i) & 1
        if bitC == 0:
            flips += bitA + bitB
        else:
            if bitA == 0 and bitB == 0:
                flips += 1
    return flips


if __name__ == '__main__':
    print(minFlips(2,6,5))  # 3
    print(minFlips(4,2,7))  # 1
