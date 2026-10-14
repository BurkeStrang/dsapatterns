"""Singly linked lists, as used by the linked list patterns."""

from collections.abc import Iterable


class ListNode:
    def __init__(self, value: int, next: "ListNode | None" = None) -> None:
        self.value = value
        self.next = next

    def __repr__(self) -> str:
        return f"ListNode({self.value})"


def build_list(values: Iterable[int]) -> ListNode | None:
    """Makes a linked list holding the given values, in order."""
    head: ListNode | None = None
    for value in reversed(list(values)):
        head = ListNode(value, head)
    return head


def build_nodes(values: Iterable[int]) -> list[ListNode]:
    """Makes the nodes of a list and returns all of them, so a test can point
    a node somewhere else, for example to make a cycle."""
    nodes: list[ListNode] = []
    node = build_list(values)
    while node is not None:
        nodes.append(node)
        node = node.next
    return nodes


def list_values(head: ListNode | None) -> list[int]:
    """Collects the values of a list, so two lists are easy to compare. It
    stops after 1000 nodes in case the list has a cycle."""
    values: list[int] = []
    node = head
    while node is not None and len(values) < 1000:
        values.append(node.value)
        node = node.next
    return values
