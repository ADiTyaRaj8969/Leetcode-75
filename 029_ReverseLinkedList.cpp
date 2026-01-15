// Topic: Linked List
// Reverse Linked List: Reverse the order of nodes in a singly linked list.
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

ListNode* reverseListIter(ListNode* head)
{
    ListNode* prev = nullptr;
    while (head)
    {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

ListNode* reverseListRec(ListNode* head)
{
    if (!head || !head->next)
        return head;
    ListNode* p = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

void printList(ListNode* head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << '\n';
}

int main()
{
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    cout << "orig: ";
    printList(a);
    auto r = reverseListIter(a);
    cout << "iter: ";
    printList(r);

    // reverse back with recursion
    auto r2 = reverseListRec(r);
    cout << "rec:  ";
    printList(r2);
    return 0;
}
