#include "common/list.hpp"

// Given the head of a singly LinkedList, change the list in place so that
// the nodes from the second half are put, in reverse order, between the nodes
// of the first half. So 1 -> 2 -> 3 -> 4 becomes 1 -> 4 -> 2 -> 3.

ListNode *rearange_list(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    // find middle
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    ListNode *current = slow;
    ListNode *prev = nullptr;
    while (current != nullptr)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // set every other one as the reverse second half
    ListNode *first = head;
    ListNode *second = prev;
    while (second->next != nullptr)
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
