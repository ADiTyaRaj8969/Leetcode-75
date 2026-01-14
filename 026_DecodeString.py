"""
Topic: Stack / String
Decode String: decode nested k[encoded_string] using stack
Time Complexity: O(n)
Space Complexity: O(n)
"""

def decode_string(s: str) -> str:
    stack = []
    cur_num = 0
    cur_str = ''
    for ch in s:
        if ch.isdigit():
            cur_num = cur_num * 10 + int(ch)
        elif ch == '[':
            stack.append((cur_str, cur_num))
            cur_str, cur_num = '', 0
        elif ch == ']':
            last_str, num = stack.pop()
            cur_str = last_str + cur_str * num
        else:
            cur_str += ch
    return cur_str


if __name__ == '__main__':
    print(decode_string('3[a]2[bc]'))  # aaabcbc
    print(decode_string('3[a2[c]]'))   # accaccacc
