// Given a set of positive numbers,
// find the total number of subsets whose sum is equal to a given number ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=4
// Output: 3
// The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
// Note that we have two similar sets {1, 3}, because we have two '1' in our
// input.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}, S=9
// Output: 3
// The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1,
// 5}

pub fn count_subsets(num: &[u32], sum: u32) -> usize {
    count_subsets_recursive(num, sum, 0)
}

fn count_subsets_recursive(
    num: &[u32],
    sum: u32,
    current_index: usize,
) -> usize {
    // base checks
    if sum == 0 {
        return 1;
    }

    if current_index >= num.len() {
        return 0;
    }

    // recursive call after selecting the number at the current_index
    // if the number at current_index exceeds the sum, we shouldn't process
    // this
    let mut sum1 = 0;
    if num[current_index] <= sum {
        sum1 = count_subsets_recursive(
            num,
            sum - num[current_index],
            current_index + 1,
        );
    }

    // recursive call after excluding the number at the current_index
    let sum2 = count_subsets_recursive(num, sum, current_index + 1);

    sum1 + sum2
}
