use super::shared::ListNode;

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

pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    // An empty stack to store nodes in descending order
    let mut stack: Vec<Box<ListNode>> = Vec::new();

    let mut cur = head;
    while let Some(mut node) = cur {
        // a node is owned by the node before it, so take each one off the
        // list before it goes on the stack
        cur = node.next.take();
        while stack.last().is_some_and(|top| top.val < node.val) {
            stack.pop(); // Pop from the stack
        }
        stack.push(node); // Push the current node onto the stack
    }

    // The nodes left on the stack are the modified list; link them back
    // together, starting from the last one
    let mut result = None;
    while let Some(mut node) = stack.pop() {
        node.next = result;
        result = Some(node);
    }

    result
}
