use std::collections::VecDeque;

// Given a set of distinct numbers, find all of its permutations.
//
// Example 1:
// Input: [1,3,5]
// Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]

pub fn find_permutations(nums: &[i32]) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    let mut permutations = VecDeque::new();
    permutations.push_back(Vec::new());
    for &current_number in nums {
        // we will take all existing permutations and add the current number
        // to create new permutations
        let n = permutations.len();
        for _ in 0..n {
            let old_permutation = permutations.pop_front().unwrap();
            // create a new permutation by adding the current number at every
            // position
            for j in 0..=old_permutation.len() {
                let mut new_permutation = old_permutation.clone();
                new_permutation.insert(j, current_number);
                if new_permutation.len() == nums.len() {
                    result.push(new_permutation);
                } else {
                    permutations.push_back(new_permutation);
                }
            }
        }
    }
    result
}
