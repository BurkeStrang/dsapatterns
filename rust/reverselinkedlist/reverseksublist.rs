use super::shared::ListNode;

// Given the head of a LinkedList and a number ‘k’,
// reverse every ‘k’ sized sub-list starting from the head.
//
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.

pub fn reverse_k_sub(
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

    loop {
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

        // move to the last node of the sub-list; it is the previous part of
        // the next sub-list
        while last_node_of_previous_part.next.is_some() {
            last_node_of_previous_part =
                last_node_of_previous_part.next.as_mut().unwrap();
        }

        // break, if we've reached the end of the LinkedList
        if current.is_none() {
            break;
        }

        // connect with the next part
        last_node_of_previous_part.next = current;
    }

    dummy.next
}
