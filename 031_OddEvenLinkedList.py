"""
Topic: Linked List / Pointers
Odd Even Linked List: group nodes at odd indices then even indices
Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def odd_even_list(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head: return None
    odd = head
    even = head.next
    even_head = even
    while even and even.next:
        odd.next = even.next
        odd = odd.next
        even.next = odd.next
        even = even.next
    odd.next = even_head
    return head

def make_list(vals):
    dummy = ListNode(0); cur = dummy
    for v in vals: cur.next = ListNode(v); cur = cur.next
    return dummy.next

def to_list(head):
    res = []
    while head: res.append(head.val); head = head.next
    return res

if __name__ == '__main__':
    h = make_list([1,2,3,4,5])
    print(to_list(odd_even_list(h)))  # [1,3,5,2,4]
    h2 = make_list([2,1,3,5,6,4,7])
    print(to_list(odd_even_list(h2)))  # [2,3,6,7,1,5,4]
