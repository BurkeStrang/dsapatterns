// Singly linked lists, as used by the linked list patterns.

export class ListNode {
  value: number;
  next: ListNode | null;

  constructor(value: number, next: ListNode | null = null) {
    this.value = value;
    this.next = next;
  }
}

// buildList makes a linked list holding the given values, in order.
export function buildList(values: number[]): ListNode | null {
  let head: ListNode | null = null;
  for (let i = values.length - 1; i >= 0; i--) {
    head = new ListNode(values[i], head);
  }
  return head;
}

// buildNodes makes the nodes of a list and returns all of them, so a test
// can point a node somewhere else, for example to make a cycle.
export function buildNodes(values: number[]): ListNode[] {
  const nodes: ListNode[] = [];
  for (let node = buildList(values); node !== null; node = node.next) {
    nodes.push(node);
  }
  return nodes;
}

// listValues collects the values of a list, so two lists are easy to
// compare. It stops after 1000 nodes in case the list has a cycle.
export function listValues(head: ListNode | null): number[] {
  const values: number[] = [];
  for (let node = head; node !== null && values.length < 1000;) {
    values.push(node.value);
    node = node.next;
  }
  return values;
}
