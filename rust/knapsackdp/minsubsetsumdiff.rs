// Given a set of positive numbers,
// partition the set into two subsets with minimum difference between their
// subset sums.
//
// Example 1:
// Input: {1, 2, 3, 9}
// Output: 3
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} &
// {9}.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}
// Output: 0
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of number is '0'. Following are the two subsets: {1, 2, 5} &
// {7, 1}.
//
// Example 3:
// Input: {1, 3, 100, 4}
// Output: 92
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} &
// {100}.

pub fn can_partition_min(num: &[i32]) -> i32 {
    can_partition_min_recursive(num, 0, 0, 0)
}

fn can_partition_min_recursive(
    num: &[i32],
    current_index: usize,
    sum1: i32,
    sum2: i32,
) -> i32 {
    // Base check
    if current_index == num.len() {
        return (sum1 - sum2).abs();
    }

    // Recursive call after including the number at the current_index in the
    // first set
    let diff1 = can_partition_min_recursive(
        num,
        current_index + 1,
        sum1 + num[current_index],
        sum2,
    );

    // Recursive call after including the number at the current_index in the
    // second set
    let diff2 = can_partition_min_recursive(
        num,
        current_index + 1,
        sum1,
        sum2 + num[current_index],
    );

    diff1.min(diff2)
}
