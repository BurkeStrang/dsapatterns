#include "common/list.hpp"

// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

ListNode *reverse_alt(ListNode *head, int k)
{
    if (k <= 1 || head == nullptr)
    {
        return head;
    }

    ListNode *current = head;
    ListNode *previous = nullptr;
    while (current != nullptr) // break if we've reached the end of the list
    {
        ListNode *last_node_of_previous_part = previous;
        // after reversing the LinkedList 'current' will become the last node
        // of the sub-list
        ListNode *last_node_of_sub_list = current;
        // reverse 'k' nodes
        for (int i = 0; current != nullptr && i < k; i++)
        {
            ListNode *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        // connect with the previous part
        if (last_node_of_previous_part != nullptr)
        {
            last_node_of_previous_part->next = previous;
        }
        else
        {
            // this means we are changing the first node (head) of the
            // LinkedList
            head = previous;
        }

        // connect with the next part
        last_node_of_sub_list->next = current;

        // skip 'k' nodes
        for (int i = 0; current != nullptr && i < k; i++)
        {
            previous = current;
            current = current->next;
        }
    }

    return head;
}
