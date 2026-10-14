use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given an array,
// find the sum of all numbers between the K1’th and K2’th smallest elements of
// that array.
//
// Example 1:
// Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
// Output: 23
// Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum
// of numbers coming
// between 5 and 15 is 23 (11+12).

// Example 2:
// Input: [3, 5, 8, 7], and K1=1, K2=4
// Output: 12
// Explanation: The sum of the numbers between the 1st smallest number (3) and
// the 4th smallest
// number (8) is 12 (5+7).

pub fn find_sum_of_elements(nums: &[i32], k1: usize, k2: usize) -> i32 {
    // Insert all numbers into the min heap
    let mut min_heap: BinaryHeap<Reverse<i32>> =
        nums.iter().map(|&num| Reverse(num)).collect();

    // Remove k1 smallest numbers from the min heap
    for _ in 0..k1 {
        min_heap.pop();
    }

    let mut element_sum = 0;
    // Sum next k2-k1-1 numbers
    for _ in k1 + 1..k2 {
        let Some(Reverse(num)) = min_heap.pop() else {
            break;
        };
        element_sum += num;
    }

    element_sum
}
