use std::collections::HashSet;

// Given an unsorted array containing numbers and a number ‘k’,
// find the first ‘k’ missing positive numbers in the array.
//
// Example 1:
// Input: [3, -1, 4, 5, 5], k=3
// Output: [1, 2, 6]
// Explanation: The smallest missing positive numbers are 1, 2 and 6.
//
// Example 2:
// Input: [2, 3, 4], k=3
// Output: [1, 5, 6]
// Explanation: The smallest missing positive numbers are 1, 5 and 6.
//
// Example 3:
// Input: [-2, -3, 4], k=2
// Output: [1, 2]
// Explanation: The smallest missing positive numbers are 1 and 2.
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= k <= 1000

pub fn find_first_k(nums: &mut [i32], k: usize) -> Vec<i32> {
    let n = nums.len() as i32;
    let mut i = 0;

    // Phase 1: Rearrange elements to their correct positions
    while i < nums.len() {
        if nums[i] > 0
            && nums[i] <= n
            && nums[i] != nums[(nums[i] - 1) as usize]
        {
            // Swap elements to their correct positions
            nums.swap(i, (nums[i] - 1) as usize);
        } else {
            i += 1;
        }
    }

    let mut missing_numbers = Vec::new();
    let mut extra_numbers = HashSet::new();

    // Phase 2: Identify missing and extra numbers
    for i in 0..nums.len() {
        if missing_numbers.len() == k {
            break;
        }
        if nums[i] != i as i32 + 1 {
            missing_numbers.push(i as i32 + 1); // Track missing numbers
            extra_numbers.insert(nums[i]); // Track extra numbers
        }
    }

    // Phase 3: Find remaining missing numbers
    let mut candidate_number = n + 1;
    while missing_numbers.len() < k {
        // Ignore if the array contains the candidate number
        if !extra_numbers.contains(&candidate_number) {
            missing_numbers.push(candidate_number);
        }
        candidate_number += 1;
    }

    missing_numbers
}
