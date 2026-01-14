"""
Topic: Stack / String
Removing Stars From a String: process '*' to remove previous char using stack
Time Complexity: O(n)
Space Complexity: O(n)
"""

def remove_stars(s: str) -> str:
    res = []
    for c in s:
        if c == '*':
            if res: res.pop()
        else:
            res.append(c)
    return ''.join(res)


if __name__ == '__main__':
    print(remove_stars('leet**cod*e'))  # 'lecode'
    print(remove_stars('erase*****'))   # ''
