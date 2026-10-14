// Given the head of a Singly LinkedList, write a method to check if the
// LinkedList is a palindrome or not.
//
// Your algorithm should use constant space and the input LinkedList should be
// in the original form once the algorithm is finished.
// The algorithm should have O(N) time complexity where ‘N’ is the number of
// nodes in the LinkedList.
//
// Example 1:
//
// Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
// Output: true
// Example 2:
//
// Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
// Output: false
// Constraints:
//
// The number of nodes in the list is in the range [].
// 0 <= Node.val <= 9

import type { ListNode } from "../common/list.ts";

export function reverse(head: ListNode | null): ListNode | null {
  let prev: ListNode | null = null;
  while (head !== null) {
    const next: ListNode | null = head.next;
    head.next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

export function isPalindrome(head: ListNode | null): boolean {
  if (head === null || head.next === null) {
    return true;
  }

  // find middle of the LinkedList
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let headSecondHalf = reverse(slow); // reverse the second half
  // store the head of reversed part to revert back later
  const copyHeadSecondHalf = headSecondHalf;

  // compare the first and the second half
  let first: ListNode | null = head;
  while (first !== null && headSecondHalf !== null) {
    if (first.value !== headSecondHalf.value) {
      break; // not a palindrome
    }
    first = first.next;
    headSecondHalf = headSecondHalf.next;
  }

  reverse(copyHeadSecondHalf); // revert the reverse of the second half

  // if both halves match, one of them ran out
  return first === null || headSecondHalf === null;
}
