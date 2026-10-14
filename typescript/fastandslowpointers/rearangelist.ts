// Given the head of a singly LinkedList, change the list in place so that
// the nodes from the second half are put, in reverse order, between the nodes
// of the first half. So 1 -> 2 -> 3 -> 4 becomes 1 -> 4 -> 2 -> 3.

import type { ListNode } from "../common/list.ts";

export function rearangeList(head: ListNode | null): ListNode | null {
  if (head === null) {
    return null;
  }

  // find middle
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    slow = slow.next;
    fast = fast.next.next;
  }

  // reverse second half
  let current = slow;
  let prev: ListNode | null = null;
  while (current !== null) {
    const next: ListNode | null = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  // set every other one as the reverse second half
  let first: ListNode | null = head;
  let second = prev;
  while (first !== null && second?.next != null) {
    const tmp1: ListNode | null = first.next;
    const tmp2: ListNode | null = second.next;
    first.next = second;
    second.next = tmp1;
    first = tmp1;
    second = tmp2;
  }
  return head;
}
