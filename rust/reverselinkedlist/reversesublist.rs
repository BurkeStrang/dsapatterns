use super::shared::ListNode;

// Given the head of a LinkedList and two positions ‘p’ and ‘q’,
// reverse the LinkedList from position ‘p’ to ‘q’.

pub fn reverse_sub(
    head: Option<Box<ListNode>>,
    p: usize,
    q: usize,
) -> Option<Box<ListNode>> {
    if p == q {
        return head;
    }

    // a node in front of the head, so that the part before index 'p' always
    // has a last node, even when p == 1
    let mut dummy = Box::new(ListNode { val: 0, next: head });

    // we are interested in three parts of the LinkedList, part before index
    // 'p', part between 'p' and 'q', and the part after index 'q'

    // after skipping 'p-1' nodes, this points to the node at index 'p-1'
    let mut last_node_of_first_part = &mut dummy;
    for _ in 1..p {
        if last_node_of_first_part.next.is_none() {
            break;
        }
        last_node_of_first_part =
            last_node_of_first_part.next.as_mut().unwrap();
    }

    // reverse nodes between 'p' and 'q'
    let mut current = last_node_of_first_part.next.take();
    let mut previous = None;
    for _ in 0..q - p + 1 {
        let Some(mut node) = current.take() else {
            break;
        };
        current = node.next.take();
        node.next = previous;
        previous = Some(node);
    }

    // connect with the first part: 'previous' is now the first node of the
    // sub-list
    last_node_of_first_part.next = previous;

    // connect with the last part, which goes after the last node of the
    // sub-list
    let mut last_node_of_sub_list = last_node_of_first_part;
    while last_node_of_sub_list.next.is_some() {
        last_node_of_sub_list = last_node_of_sub_list.next.as_mut().unwrap();
    }
    last_node_of_sub_list.next = current;

    dummy.next
}
