#include "fastandslowpointers/shared.h"

ListNode *find_middle
(
    ListNode *head
)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
