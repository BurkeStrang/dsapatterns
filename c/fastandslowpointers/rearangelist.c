#include "fastandslowpointers/shared.h"

ListNode *rearange_list
(
    ListNode *head
)
{
    if (head == NULL)
    {
        return NULL;
    }

    // find middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    ListNode *curr = slow;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // set every other one as the reverse second half
    ListNode *first = head;
    ListNode *second = prev;
    while (second->next != NULL)
    {
        ListNode *tmp1 = first->next;
        ListNode *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
    return head;
}
