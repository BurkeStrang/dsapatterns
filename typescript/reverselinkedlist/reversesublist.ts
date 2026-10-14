// Given the head of a LinkedList and two positions ‘p’ and ‘q’,
// reverse the LinkedList from position ‘p’ to ‘q’.

import type { ListNode } from "../common/list.ts";

export function reverseSub(
  head: ListNode | null,
  p: number,
  q: number,
): ListNode | null {
  if (p === q || head === null) {
    return head;
  }

  // after skipping 'p-1' nodes, current will point to the node at index 'p'
  let current: ListNode | null = head;
  let previous: ListNode | null = null;
  for (let i = 0; current !== null && i < p - 1; i++) {
    previous = current;
    current = current.next;
  }
  if (current === null) {
    return head; // the list is shorter than 'p'
  }

  // we are interested in three parts of the LinkedList, part before index
  // 'p', part between 'p' and 'q', and the part after index 'q'
  const lastNodeOfFirstPart = previous; // the node at index 'p-1'
  // after reversing the LinkedList 'current' will become the last node of
  // the sub-list
  const lastNodeOfSubList: ListNode = current;

  // reverse nodes between 'p' and 'q'
  for (let i = 0; current !== null && i < q - p + 1; i++) {
    const next: ListNode | null = current.next;
    current.next = previous;
    previous = current;
    current = next;
  }

  // connect with the first part
  if (lastNodeOfFirstPart !== null) {
    // 'previous' is now the first node of the sub-list
    lastNodeOfFirstPart.next = previous;
  } else {
    // this means p === 1 i.e., we are changing the first node (head) of the
    // LinkedList
    head = previous;
  }

  // connect with the last part
  lastNodeOfSubList.next = current;
  return head;
}
