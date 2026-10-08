#include "fastandslowpointers/shared.h"

#include <stdbool.h>

// Given the head of a Singly LinkedList, write a function to determine if the
// LinkedList has a cycle in it or not.

bool has_cycle
(
    ListNode *head
)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
