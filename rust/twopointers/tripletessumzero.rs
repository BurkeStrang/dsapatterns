use std::cmp::Ordering;

// Given an array of unsorted numbers, find all unique triplets in it that add
// up to zero.
//
// Examples
// Example 1
// Input: [-3, 0, 1, 2, -1, 1, -2]
// Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
// Explanation: There are four unique triplets whose sum is equal to zero.
// Example 2
// Input: [-5, 2, -1, -2, 3]
// Output: [[-5, 2, 3], [-2, -1, 3]]
// Explanation: There are two unique triplets whose sum is equal to zero.
// Constraints:
//
// 3 <= arr.length <= 3000
// -105 <= arr[i] <= 105

pub fn search_triplets(arr: &mut [i32]) -> Vec<Vec<i32>> {
    arr.sort_unstable();
    let mut triplets = Vec::new();
    for i in 0..arr.len().saturating_sub(2) {
        // skip same element to avoid duplicate triplets
        if i > 0 && arr[i] == arr[i - 1] {
            continue;
        }
        search_pair(arr, -arr[i], i + 1, &mut triplets);
    }
    triplets
}

fn search_pair(
    arr: &[i32],
    target_sum: i32,
    mut left: usize,
    triplets: &mut Vec<Vec<i32>>,
) {
    let mut right = arr.len() - 1;
    while left < right {
        let current_sum = arr[left] + arr[right];
        match current_sum.cmp(&target_sum) {
            // found the triplet
            Ordering::Equal => {
                triplets.push(vec![-target_sum, arr[left], arr[right]]);
                left += 1;
                right -= 1;
                // skip same elements to avoid duplicate triplets
                while left < right && arr[left] == arr[left - 1] {
                    left += 1;
                }
                while left < right && arr[right] == arr[right + 1] {
                    right -= 1;
                }
            }
            // we need a pair with a bigger sum
            Ordering::Less => left += 1,
            // we need a pair with a smaller sum
            Ordering::Greater => right -= 1,
        }
    }
}
