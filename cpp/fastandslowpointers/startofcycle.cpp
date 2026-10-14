#include "common/list.hpp"

// Given the head of a singly LinkedList that contains a cycle, find the node
// where the cycle starts. Returns None if there is no cycle.

ListNode *find_cycle_start(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break; // found the cycle
        }
    }

    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr; // no cycle
    }

    // move both pointers one step at a time; they meet at the start
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
