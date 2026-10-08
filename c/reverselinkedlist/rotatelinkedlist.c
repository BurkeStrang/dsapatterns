#include "reverselinkedlist/shared.h"

// Given the head of a Singly LinkedList and a number ‘k’,
// rotate the LinkedList to the right by ‘k’ nodes.

// Constraints:
//
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9

ListNode *rotate
(
    ListNode *head,
    int rotations
)
{
    // base cases
    if (head == NULL || head->next == NULL || rotations <= 0)
    {
        return head;
    }

    // find the length and the last node of the list
    ListNode *last_node = head;
    int list_length = 1;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
        list_length++;
    }

    // connect the last node with the head to a circular list
    last_node->next = head;
    // no need to do rotations more than the length of the list
    rotations %= list_length;
    int skip_length = list_length - rotations;
    ListNode *last_node_of_rotated_list = head;
    for (int i = 0; i < skip_length - 1; i++)
    {
        last_node_of_rotated_list = last_node_of_rotated_list->next;
    }

    // 'last_node_of_rotated_list->next' is pointing to the sub-list of 'k'
    // ending nodes
    head = last_node_of_rotated_list->next;
    last_node_of_rotated_list->next = NULL;
    return head;
}
