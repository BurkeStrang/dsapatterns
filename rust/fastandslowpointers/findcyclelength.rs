use super::shared::{Link, next, same_node};

// Given the head of a LinkedList with a cycle, find the length of the cycle.
// Returns 0 if there is no cycle.

pub fn find_cycle_length(head: &Link) -> usize {
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        slow = next(&slow);
        fast = next(&next(&fast));
        if same_node(&slow, &fast) {
            return calc_cycle_distance(&slow);
        }
    }
    0
}

fn calc_cycle_distance(slow: &Link) -> usize {
    let mut current = next(slow);
    let mut current_count = 1;
    while !same_node(&current, slow) {
        current = next(&current);
        current_count += 1;
    }
    current_count
}
