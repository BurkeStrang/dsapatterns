use super::shared::ListNode;

// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

pub fn reverse_alt(
    head: Option<Box<ListNode>>,
    k: usize,
) -> Option<Box<ListNode>> {
    if k <= 1 || head.is_none() {
        return head;
    }

    // a node in front of the head, so that the first sub-list has a previous
    // part to connect to like every other sub-list
    let mut dummy = Box::new(ListNode { val: 0, next: head });
    let mut last_node_of_previous_part = &mut dummy;

    // break if we've reached the end of the list
    while last_node_of_previous_part.next.is_some() {
        // reverse 'k' nodes
        let mut current = last_node_of_previous_part.next.take();
        let mut previous = None;
        for _ in 0..k {
            let Some(mut node) = current.take() else {
                break;
            };
            current = node.next.take();
            node.next = previous;
            previous = Some(node);
        }

        // connect with the previous part: 'previous' is now the first node of
        // the sub-list
        last_node_of_previous_part.next = previous;

        // move to the last node of the sub-list and connect with the next part
        while last_node_of_previous_part.next.is_some() {
            last_node_of_previous_part =
                last_node_of_previous_part.next.as_mut().unwrap();
        }
        last_node_of_previous_part.next = current;

        // skip 'k' nodes
        for _ in 0..k {
            if last_node_of_previous_part.next.is_none() {
                break;
            }
            last_node_of_previous_part =
                last_node_of_previous_part.next.as_mut().unwrap();
        }
    }

    dummy.next
}
