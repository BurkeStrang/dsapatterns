#include "common/list.hpp"

// Given the head of a singly LinkedList, return the middle node. If the list
// has an even number of nodes, return the second of the two middle nodes.

ListNode *find_middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
