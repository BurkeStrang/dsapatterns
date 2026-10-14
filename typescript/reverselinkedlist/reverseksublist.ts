// Given the head of a LinkedList and a number ‘k’,
// reverse every ‘k’ sized sub-list starting from the head.
//
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.

import type { ListNode } from "../common/list.ts";

export function reverseKSub(head: ListNode | null, k: number): ListNode | null {
  if (k <= 1 || head === null) {
    return head;
  }

  let current: ListNode | null = head;
  let previous: ListNode | null = null;
  // the loop ends once we've reached the end of the LinkedList
  while (current !== null) {
    const lastNodeOfPreviousPart = previous;
    // after reversing the LinkedList 'current' will become the last node of
    // the sub-list
    const lastNodeOfSubList: ListNode = current;

    // reverse 'k' nodes
    for (let i = 0; current !== null && i < k; i++) {
      const next: ListNode | null = current.next;
      current.next = previous;
      previous = current;
      current = next;
    }

    // connect with the previous part
    if (lastNodeOfPreviousPart !== null) {
      lastNodeOfPreviousPart.next = previous;
    } else {
      // this means we are changing the first node (head) of the LinkedList
      head = previous;
    }

    // connect with the next part
    lastNodeOfSubList.next = current;

    // prepare for the next sub-list
    previous = lastNodeOfSubList;
  }
  return head;
}
