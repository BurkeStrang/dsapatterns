use std::cmp::Ordering;

// Given an array of unsorted numbers and a target number,
// find all unique quadruplets in it, whose sum is equal to the target number.
//
// Example 1:
//
// Input: [4, 1, 2, -1, 1, -3], target=1
// Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Example 2:
//
// Input: [2, 0, -1, 1, -2, 2], target=2
// Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Constraints:
//
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

pub fn search_quadruplets(arr: &mut [i32], target: i32) -> Vec<Vec<i32>> {
    arr.sort_unstable();
    let mut quadruplets = Vec::new();
    for i in 0..arr.len().saturating_sub(3) {
        // skip same element to avoid duplicate quadruplets
        if i > 0 && arr[i] == arr[i - 1] {
            continue;
        }
        for j in i + 1..arr.len() - 2 {
            // skip same element to avoid duplicate quadruplets
            if j > i + 1 && arr[j] == arr[j - 1] {
                continue;
            }
            search_pairs(arr, target, i, j, &mut quadruplets);
        }
    }
    quadruplets
}

fn search_pairs(
    arr: &[i32],
    target_sum: i32,
    first: usize,
    second: usize,
    quadruplets: &mut Vec<Vec<i32>>,
) {
    let mut left = second + 1;
    let mut right = arr.len() - 1;
    while left < right {
        let sum = arr[first] + arr[second] + arr[left] + arr[right];
        match sum.cmp(&target_sum) {
            // found the quadruplet
            Ordering::Equal => {
                quadruplets.push(vec![
                    arr[first],
                    arr[second],
                    arr[left],
                    arr[right],
                ]);
                left += 1;
                right -= 1;
                // skip same elements to avoid duplicate quadruplets
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
