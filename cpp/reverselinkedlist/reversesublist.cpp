#include "common/list.hpp"

// Given the head of a LinkedList and two positions ‘p’ and ‘q’,
// reverse the LinkedList from position ‘p’ to ‘q’.

ListNode *reverse_sub(ListNode *head, int p, int q)
{
    if (p == q)
    {
        return head;
    }

    // after skipping 'p-1' nodes, current will point to the node at index 'p'
    ListNode *current = head;
    ListNode *previous = nullptr;
    for (int i = 0; current != nullptr && i < p - 1; i++)
    {
        previous = current;
        current = current->next;
    }

    // we are interested in three parts of the LinkedList, part before index
    // 'p', part between 'p' and 'q', and the part after index 'q'
    ListNode *last_node_of_first_part = previous; // the node at index 'p-1'
    // after reversing the LinkedList 'current' will become the last node of
    // the sub-list
    ListNode *last_node_of_sub_list = current;
    // reverse nodes between 'p' and 'q'
    for (int i = 0; current != nullptr && i < q - p + 1; i++)
    {
        ListNode *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    // connect with the first part
    if (last_node_of_first_part != nullptr)
    {
        // 'previous' is now the first node of the sub-list
        last_node_of_first_part->next = previous;
    }
    else
    {
        // this means p == 1 i.e., we are changing the first node (head) of the
        // LinkedList
        head = previous;
    }

    // connect with the last part
    last_node_of_sub_list->next = current;
    return head;
}
