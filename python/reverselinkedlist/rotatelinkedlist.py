"""
Given the head of a Singly LinkedList and a number ‘k’,
rotate the LinkedList to the right by ‘k’ nodes.
"""

from common.list import ListNode


def rotate(head: ListNode | None, rotations: int) -> ListNode | None:
    if head is None or head.next is None or rotations <= 0:
        return head

    # find the length and the last node of the list
    last_node = head
    list_length = 1
    while last_node.next is not None:
        last_node = last_node.next
        list_length += 1

    # connect the last node with the head to make it a circular list
    last_node.next = head
    # no need to do rotations more than the length of the list
    rotations %= list_length
    skip_length = list_length - rotations
    last_node_of_rotated_list = head
    for _ in range(skip_length - 1):
        assert last_node_of_rotated_list.next is not None  # the list is a ring
        last_node_of_rotated_list = last_node_of_rotated_list.next

    # 'last_node_of_rotated_list.next' is pointing to the sub-list of 'k'
    # ending nodes
    head = last_node_of_rotated_list.next
    last_node_of_rotated_list.next = None
    return head
