#include "reverselinkedlist/shared.h"

// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

ListNode *reverse_alt
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
    while (current != NULL)
    { // break if we've reached the end of the list
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

        // skip 'k' nodes
        for (int i = 0; current != NULL && i < k; i++)
        {
            previous = current;
            current = current->next;
        }
    }

    return head;
}
