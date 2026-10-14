// There are n houses built in a line.
// A thief wants to steal the maximum possible money from these houses.
// The only restriction the thief has is that he can't steal from two
// consecutive houses,
// as that would alert the security system. How should the thief maximize his
// stealing?
//
// Problem Statement
// Given a number array representing the wealth of n houses,
// determine the maximum amount of money the thief can steal without alerting
// the security system.
//
// Example 1:
// Input: {2, 5, 1, 3, 6, 2, 4}
// Output: 15
// Explanation: The thief should steal from houses 5 + 6 + 4
//
// Example 2:
// Input: {2, 10, 14, 8, 1}
// Output: 18
// Explanation: The thief should steal from houses 10 + 8

pub fn find_max_steal(wealth: &[i32]) -> i32 {
    find_max_steal_recursive(wealth, 0)
}

fn find_max_steal_recursive(wealth: &[i32], current_index: usize) -> i32 {
    if current_index >= wealth.len() {
        return 0;
    }

    // steal from current house and skip one to steal from the next house
    let steal_current = wealth[current_index]
        + find_max_steal_recursive(wealth, current_index + 2);
    // skip current house to steal from the adjacent house
    let skip_current = find_max_steal_recursive(wealth, current_index + 1);

    steal_current.max(skip_current)
}
