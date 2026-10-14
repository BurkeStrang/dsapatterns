// Given the head of a Singly LinkedList and a number ‘k’,
// rotate the LinkedList to the right by ‘k’ nodes.

import type { ListNode } from "../common/list.ts";

export function rotate(
  head: ListNode | null,
  rotations: number,
): ListNode | null {
  if (head === null || head.next === null || rotations <= 0) {
    return head;
  }

  // find the length and the last node of the list
  let lastNode = head;
  let listLength = 1;
  while (lastNode.next !== null) {
    lastNode = lastNode.next;
    listLength++;
  }

  // connect the last node with the head to make it a circular list
  lastNode.next = head;
  // no need to do rotations more than the length of the list
  rotations %= listLength;
  const skipLength = listLength - rotations;
  let lastNodeOfRotatedList = head;
  for (let i = 0; i < skipLength - 1; i++) {
    // the list is a ring now, so there is always a next node
    lastNodeOfRotatedList = lastNodeOfRotatedList.next ?? head;
  }

  // 'lastNodeOfRotatedList.next' is pointing to the sub-list of 'k' ending
  // nodes
  const newHead = lastNodeOfRotatedList.next;
  lastNodeOfRotatedList.next = null;
  return newHead;
}
