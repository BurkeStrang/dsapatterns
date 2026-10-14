use super::shared::{Link, next, same_node};

// Given the head of a singly LinkedList that contains a cycle, find the node
// where the cycle starts. Returns None if there is no cycle.

pub fn find_cycle_start(head: &Link) -> Link {
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        slow = next(&slow);
        fast = next(&next(&fast));
        if same_node(&slow, &fast) {
            break;
        }
    }

    if fast.is_none() || next(&fast).is_none() {
        return None;
    }

    slow = head.clone();
    while !same_node(&slow, &fast) {
        slow = next(&slow);
        fast = next(&fast);
    }
    slow
}
