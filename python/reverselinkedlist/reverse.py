"""
Given the head of a Singly LinkedList, reverse the LinkedList.
Write a function to return the new head of the reversed LinkedList.
"""

from common.list import ListNode


def reverse(head: ListNode | None) -> ListNode | None:
    previous = None
    current = head
    while current is not None:
        next = current.next
        current.next = previous
        previous = current
        current = next
    return previous
