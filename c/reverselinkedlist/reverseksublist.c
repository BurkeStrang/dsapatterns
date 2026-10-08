#include "reverselinkedlist/shared.h"

#include <stdbool.h>

// Given the head of a LinkedList and a number ‘k’,
// reverse every ‘k’ sized sub-list starting from the head.
//
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.

ListNode *reverse_k_sub
(
    ListNode *head,
    int k
)
{
    if (k <= 1 || head == NULL)
    {
        return head;
    }

    ListNode *current = head;
    ListNode *previous = NULL;
    while (true)
    {
        ListNode *last_node_of_previous_part = previous;
        // after reversing the list 'current' will become the last node of the
        // sub-list
        ListNode *last_node_of_sub_list = current;
        ListNode *next =
            NULL; // will be used to temporarily store the next node
        // reverse 'k' nodes
        for (int i = 0; current != NULL && i < k; i++)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        // connect with the previous part
        if (last_node_of_previous_part != NULL)
        {
            // 'previous' is now the first node of the sub-list
            last_node_of_previous_part->next = previous;
        }
        else
        {
            // this means we are changing the first node (head) of the list
            head = previous;
        }

        // connect with the next part
        last_node_of_sub_list->next = current;

        if (current == NULL)
        { // break, if we've reached the end of the list
            break;
        }
        // prepare for the next sub-list
        previous = last_node_of_sub_list;
    }

    return head;
}
