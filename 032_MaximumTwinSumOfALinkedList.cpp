// Topic: Linked List / Two pointers
// Maximum Twin Sum of a Linked List: Pair first with last, second with second-last etc and return
// max sum. Time Complexity: O(n) Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
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

int pairSum(ListNode* head)
{
    // find middle
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = reverseList(slow);
    int best = 0;
    ListNode* p = head;
    ListNode* q = second;
    while (q)
    {
        best = max(best, p->val + q->val);
        p = p->next;
        q = q->next;
    }
    // optional: restore second half (skipped)
    return best;
}

int main()
{
    ListNode* a = new ListNode(5);
    a->next = new ListNode(4);
    a->next->next = new ListNode(2);
    a->next->next->next = new ListNode(1);
    cout << pairSum(a) << "\n";  // 6 (5+1 or 4+2 -> max 6)
    ListNode* b = new ListNode(1);
    b->next = new ListNode(100000);
    b->next->next = new ListNode(2);
    b->next->next->next = new ListNode(3);
    cout << pairSum(b) << "\n";
    return 0;
}
