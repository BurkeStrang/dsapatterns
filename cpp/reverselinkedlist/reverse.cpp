#include "common/list.hpp"

// Given the head of a Singly LinkedList, reverse the LinkedList.
// Write a function to return the new head of the reversed LinkedList.

ListNode *reverse(ListNode *head)
{
    ListNode *previous = nullptr;
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
