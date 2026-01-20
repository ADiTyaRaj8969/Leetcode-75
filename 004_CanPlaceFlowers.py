"""
Topic: Greedy / Array
Can Place Flowers: check if we can plant n flowers without adjacent planting
Time Complexity: O(n)
Space Complexity: O(1)
"""

def can_place_flowers(flowerbed, n):
    i = 0
    while i < len(flowerbed) and n > 0:
        if flowerbed[i] == 0:
            prev_empty = (i == 0) or (flowerbed[i-1] == 0)
            next_empty = (i == len(flowerbed)-1) or (flowerbed[i+1] == 0)
            if prev_empty and next_empty:
                flowerbed[i] = 1
                n -= 1
                i += 1
        i += 1
    return n == 0


if __name__ == '__main__':
    print(can_place_flowers([1,0,0,0,1], 1))  # True
    print(can_place_flowers([1,0,0,0,1], 2))  # False
