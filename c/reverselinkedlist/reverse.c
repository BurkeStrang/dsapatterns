#include "reverselinkedlist/shared.h"

// Given the head of a Singly LinkedList, reverse the LinkedList.
// Write a function to return the new head of the reversed LinkedList.

ListNode *reverse
(
    ListNode *head
)
{
    ListNode *previous = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = previous;
        previous = curr;
        curr = temp;
    }
    return previous;
}
