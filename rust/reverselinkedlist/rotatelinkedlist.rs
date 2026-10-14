use super::shared::ListNode;

// Given the head of a Singly LinkedList and a number ‘k’,
// rotate the LinkedList to the right by ‘k’ nodes.

// Constraints:
//
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9

pub fn rotate(
    mut head: Option<Box<ListNode>>,
    rotations: usize,
) -> Option<Box<ListNode>> {
    // find the length of the list
    let mut list_length = 0;
    let mut node = &head;
    while let Some(n) = node {
        list_length += 1;
        node = &n.next;
    }

    // base cases
    if list_length <= 1 {
        return head;
    }

    // no need to do rotations more than the length of the list
    let rotations = rotations % list_length;
    if rotations == 0 {
        return head;
    }

    let skip_length = list_length - rotations;
    let mut last_node_of_rotated_list = head.as_mut().unwrap();
    for _ in 1..skip_length {
        last_node_of_rotated_list =
            last_node_of_rotated_list.next.as_mut().unwrap();
    }

    // 'last_node_of_rotated_list.next' is pointing to the sub-list of 'k'
    // ending nodes; cut it off, it becomes the start of the rotated list
    let mut new_head = last_node_of_rotated_list.next.take();

    // connect the last node of the list with the old head
    let mut last_node = new_head.as_mut().unwrap();
    while last_node.next.is_some() {
        last_node = last_node.next.as_mut().unwrap();
    }
    last_node.next = head;

    new_head
}
