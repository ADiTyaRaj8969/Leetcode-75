// Topic: Linked List / Two pointers
// Delete the Middle Node of a Linked List: Find and remove the middle node from a linked list.
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

ListNode* deleteMiddle(ListNode* head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is node before middle
    ListNode* todel = slow->next;
    slow->next = slow->next->next;
    delete todel;
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
    cout << '\n';
}

int main()
{
    ListNode* a = new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(4);
    a->next->next->next = new ListNode(7);
    a->next->next->next->next = new ListNode(1);
    a->next->next->next->next->next = new ListNode(2);
    a->next->next->next->next->next->next = new ListNode(6);
    cout << "orig: ";
    printList(a);
    auto r = deleteMiddle(a);
    cout << "after: ";
    printList(r);

    ListNode* b = new ListNode(1);
    cout << "single orig: ";
    printList(b);
    auto r2 = deleteMiddle(b);
    cout << "single after: ";
    if (!r2)
        cout << "(empty)\n";
    else
        printList(r2);
    return 0;
}
