"""
Given the head of a LinkedList and a number ‘k’,
reverse every alternating ‘k’ sized sub-list starting from the head.
If, in the end, you are left with a sub-list with less than ‘k’ elements,
reverse it too.

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
"""

from common.list import ListNode


def reverse_alt(head: ListNode | None, k: int) -> ListNode | None:
    if k <= 1 or head is None:
        return head

    current: ListNode | None = head
    previous: ListNode | None = None
    while current is not None:  # break if we've reached the end of the list
        last_node_of_previous_part = previous
        # after reversing the LinkedList 'current' will become the last node
        # of the sub-list
        last_node_of_sub_list = current

        # reverse 'k' nodes
        i = 0
        while current is not None and i < k:
            next = current.next
            current.next = previous
            previous = current
            current = next
            i += 1

        # connect with the previous part
        if last_node_of_previous_part is not None:
            last_node_of_previous_part.next = previous
        else:
            # this means we are changing the first node (head) of the
            # LinkedList
            head = previous

        # connect with the next part
        last_node_of_sub_list.next = current

        # skip 'k' nodes
        i = 0
        while current is not None and i < k:
            previous = current
            current = current.next
            i += 1
    return head
