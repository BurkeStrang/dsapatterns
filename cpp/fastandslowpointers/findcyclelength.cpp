#include "common/list.hpp"

// Given the head of a LinkedList with a cycle, find the length of the cycle.
// Returns 0 if there is no cycle.

int calc_cycle_distance(ListNode *slow)
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

int find_cycle_length(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // found the cycle
        {
            return calc_cycle_distance(slow);
        }
    }
    return 0;
}
