"""
Topic: Linked List / Two Pointers
Delete The Middle Node Of A Linked List: remove middle using slow/fast pointers
Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def delete_middle(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
        return None
    slow = head; fast = head; prev = None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    # slow is middle, prev is before it
    prev.next = slow.next
    return head

def make_list(vals):
    dummy = ListNode(0); cur = dummy
    for v in vals: cur.next = ListNode(v); cur = cur.next
    return dummy.next

def to_list(head):
    res=[]
    while head: res.append(head.val); head = head.next
    return res

if __name__ == '__main__':
    h = make_list([1,3,4,7,1,2,6])
    print(to_list(delete_middle(h)))  # [1,3,4,1,2,6]
    h2 = make_list([1,2,3,4])
    print(to_list(delete_middle(h2)))  # [1,2,4]
