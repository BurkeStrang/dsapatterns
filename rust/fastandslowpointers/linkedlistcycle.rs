use super::shared::{Link, next, same_node};

// Given the head of a singly LinkedList, determine if it has a cycle in it.

pub fn has_cycle(head: &Link) -> bool {
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        fast = next(&next(&fast));
        slow = next(&slow);
        if same_node(&slow, &fast) {
            return true;
        }
    }
    false
}
