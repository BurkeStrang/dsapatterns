// Given the head node of a singly linked list, modify the list such that any
// node that has a node with a greater value to its right gets removed. The
// function should return the head of the modified list.
//
// Examples:
// Input: 5 -> 3 -> 7 -> 4 -> 2 -> 1
// Output: 7 -> 4 -> 2 -> 1
// Explanation: 5 and 3 are removed as they have nodes with larger values to
// their right.
//
// Input: 1 -> 2 -> 3 -> 4 -> 5
// Output: 5
// Explanation: 1, 2, 3, and 4 are removed as they have nodes with larger values
// to their right.
//
// Input: 5 -> 4 -> 3 -> 2 -> 1
// Output: 5 -> 4 -> 3 -> 2 -> 1
// Explanation: None of the nodes are removed as none of them have nodes with
// larger values to their right.
//
// Constraints:
// The number of the nodes in the given list is in the range [1, 105].
// 1 <= Node.val <= 105

import type { ListNode } from "../common/list.ts";

export function removeNodes(head: ListNode | null): ListNode | null {
  // An empty stack to store nodes in descending order
  const stack: ListNode[] = [];
  for (let current = head; current !== null; current = current.next) {
    let top = stack.at(-1);
    while (top !== undefined && top.value < current.value) {
      stack.pop(); // Pop from the stack
      top = stack.at(-1);
    }
    stack.push(current); // Push the current node onto the stack
  }

  // The nodes left on the stack are the modified list; link them back
  // together, starting from the last one
  let result: ListNode | null = null;
  for (let node = stack.pop(); node !== undefined; node = stack.pop()) {
    node.next = result;
    result = node;
  }
  return result;
}
