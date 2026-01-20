"""
Topic: Two Pointers / String
Reverse Vowels of a String: swap vowels using two pointers
Time Complexity: O(n)
Space Complexity: O(n) for list conversion
"""

def reverse_vowels(s: str) -> str:
    vowels = set('aeiouAEIOU')
    arr = list(s)
    i, j = 0, len(arr)-1
    while i < j:
        if arr[i] not in vowels:
            i += 1
            continue
        if arr[j] not in vowels:
            j -= 1
            continue
        arr[i], arr[j] = arr[j], arr[i]
        i += 1; j -= 1
    return ''.join(arr)


if __name__ == '__main__':
    print(reverse_vowels('hello'))  # holle
    print(reverse_vowels('leetcode'))  # leotcede
