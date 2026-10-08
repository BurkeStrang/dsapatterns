#include "fastandslowpointers/shared.h"

// Given the head of a LinkedList with a cycle, find the length of the cycle.

int calc_cycle_distance
(
    ListNode *slow
)
{
    ListNode *current = slow->next;
    int current_count = 1;
    while (current != slow)
    {
        current = current->next;
        current_count++;
    }
    return current_count;
}

int find_cycle_length
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
        if (slow == fast)
        {
            return calc_cycle_distance(slow);
        }
    }
    return 0;
}
