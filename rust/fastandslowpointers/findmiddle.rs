use super::shared::{Link, next};

// Given the head of a singly LinkedList, return the middle node. If the list
// has an even number of nodes, return the second of the two middle nodes.

pub fn find_middle(head: &Link) -> Link {
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        slow = next(&slow);
        fast = next(&next(&fast));
    }
    slow
}
