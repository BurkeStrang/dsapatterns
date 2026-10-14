// Given the head of a Singly LinkedList, reverse the LinkedList.
// Write a function to return the new head of the reversed LinkedList.

import type { ListNode } from "../common/list.ts";

export function reverse(head: ListNode | null): ListNode | null {
  let previous: ListNode | null = null;
  let current = head;
  while (current !== null) {
    const next = current.next;
    current.next = previous;
    previous = current;
    current = next;
  }
  return previous;
}
