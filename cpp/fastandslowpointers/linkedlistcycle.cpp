#include "common/list.hpp"

// Given the head of a singly LinkedList, determine if it has a cycle in it.

bool has_cycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true; // found the cycle
        }
    }
    return false;
}
