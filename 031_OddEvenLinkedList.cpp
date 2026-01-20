// Topic: Linked List / Two pointers
// Odd Even Linked List: Reorder a linked list grouping odd-indexed nodes then even-indexed nodes.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if (!head)
        return head;
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

void printList(ListNode* h)
{
    while (h)
    {
        cout << h->val;
        if (h->next)
            cout << "->";
        h = h->next;
    }
    cout << "\n";
}

int main()
{
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    cout << "orig: ";
    printList(a);
    auto r = oddEvenList(a);
    cout << "oddEven: ";
    printList(r);  // 1->3->5->2->4
    ListNode* b = new ListNode(2);
    b->next = new ListNode(1);
    b->next->next = new ListNode(3);
    b->next->next->next = new ListNode(5);
    b->next->next->next->next = new ListNode(6);
    b->next->next->next->next->next = new ListNode(4);
    b->next->next->next->next->next->next = new ListNode(7);
    cout << "orig2: ";
    printList(b);
    printList(oddEvenList(b));
    return 0;
}
