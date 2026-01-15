"""
Topic: Linked List
Reverse Linked List: iterative and recursive solutions
Time Complexity: O(n)
Space Complexity: O(1) iterative, O(n) recursive
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_list_iter(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev

def reverse_list_rec(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
        return head
    p = reverse_list_rec(head.next)
    head.next.next = head
    head.next = None
    return p

def make_list(vals):
    dummy = ListNode(0)
    cur = dummy
    for v in vals:
        cur.next = ListNode(v)
        cur = cur.next
    return dummy.next

def to_list(head):
    res = []
    while head:
        res.append(head.val); head = head.next
    return res

if __name__ == '__main__':
    h = make_list([1,2,3,4,5])
    print(to_list(reverse_list_iter(h)))  # [5,4,3,2,1]
    h2 = make_list([1,2])
    print(to_list(reverse_list_rec(h2)))  # [2,1]
