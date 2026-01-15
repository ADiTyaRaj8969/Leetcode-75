"""
Topic: Linked List / Two Pointers
Maximum Twin Sum of a Linked List: reverse second half and compute pair sums
Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def pair_sum(head: Optional[ListNode]) -> int:
    # find middle
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    # reverse second half
    prev = None
    cur = slow
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    # compute max twin sum
    res = 0
    p1, p2 = head, prev
    while p2:
        res = max(res, p1.val + p2.val)
        p1 = p1.next; p2 = p2.next
    return res

def make_list(vals):
    dummy = ListNode(0); cur = dummy
    for v in vals: cur.next = ListNode(v); cur = cur.next
    return dummy.next

if __name__ == '__main__':
    h = make_list([5,4,2,1])
    print(pair_sum(h))  # 6 (5+1 or 4+2 => max 6)
    h2 = make_list([1,100000])
    print(pair_sum(h2))  # 100001
