// Given an array of positive numbers,
// where each element represents the max number of jumps that can be made
// forward from that element,
// write a program to find the minimum number of jumps needed to reach the end
// of the array
// (starting from the first element).
// If an element is 0, then we cannot move through that element.
//
// Example 1:
// Input = {2,1,1,1,4}
// Output = 3
// Explanation: Starting from index '0', we can reach the last index through:
// 0->2->3->4
//
// Example 2:
// Input = {1,1,3,6,9,3,0,1,3}
// Output = 4
// Explanation: Starting from index '0', we can reach the last index through:
// 0->1->2->3->8

/// Returns None if the end of the array can't be reached.
pub fn count_min_jumps(jumps: &[usize]) -> Option<usize> {
    count_min_jumps_recursive(jumps, 0)
}

fn count_min_jumps_recursive(
    jumps: &[usize],
    current_index: usize,
) -> Option<usize> {
    // if we have reached the last index, we don't need any more jumps
    if current_index + 1 >= jumps.len() {
        return Some(0);
    }

    // jumps[current_index] == 0 gives an empty range below: we can't move
    // through this element
    let mut total_jumps: Option<usize> = None;
    let start = current_index + 1;
    let end = (current_index + jumps[current_index]).min(jumps.len() - 1);

    // try every jump we can make from here and keep the best one
    for next in start..=end {
        let Some(min_jumps) = count_min_jumps_recursive(jumps, next) else {
            continue;
        };
        total_jumps = match total_jumps {
            Some(total) => Some(total.min(min_jumps + 1)),
            None => Some(min_jumps + 1),
        };
    }

    total_jumps
}
