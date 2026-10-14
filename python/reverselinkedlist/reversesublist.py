"""
Given the head of a LinkedList and two positions ‘p’ and ‘q’,
reverse the LinkedList from position ‘p’ to ‘q’.
"""

from common.list import ListNode


def reverse_sub(head: ListNode | None, p: int, q: int) -> ListNode | None:
    if p == q or head is None:
        return head

    # after skipping 'p-1' nodes, current will point to the node at index 'p'
    current: ListNode | None = head
    previous: ListNode | None = None
    i = 0
    while current is not None and i < p - 1:
        previous = current
        current = current.next
        i += 1
    if current is None:
        return head  # the list is shorter than 'p'

    # we are interested in three parts of the LinkedList, part before index
    # 'p', part between 'p' and 'q', and the part after index 'q'
    last_node_of_first_part = previous  # the node at index 'p-1'
    # after reversing the LinkedList 'current' will become the last node of
    # the sub-list
    last_node_of_sub_list = current

    # reverse nodes between 'p' and 'q'
    i = 0
    while current is not None and i < q - p + 1:
        next = current.next
        current.next = previous
        previous = current
        current = next
        i += 1

    # connect with the first part
    if last_node_of_first_part is not None:
        # 'previous' is now the first node of the sub-list
        last_node_of_first_part.next = previous
    else:
        # this means p == 1 i.e., we are changing the first node (head) of the
        # LinkedList
        head = previous

    # connect with the last part
    last_node_of_sub_list.next = current
    return head
