use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

// Given an array of numbers nums and an integer K,
// find the maximum number of distinct elements after removing exactly K
// elements from the nums array.
//
// Example 1:
// Input: nums = [7, 3, 5, 8, 5, 3, 3], K=2
// Expected Output: 3
// Explanation: We can remove two occurrences of 3 to be left with 3 distinct
// numbers [7, 3, 8],
// we have to skip 5 because it is not distinct and occurred twice.
// Another solution could be to remove one instance of '5' and '3' each to be
// left with three distinct numbers [7, 5, 8],
// in this case, we have to skip 3 because it occurred twice.
//
// Example 2:
// Input: [3, 5, 12, 11, 12], and K=3
// Expected Output: 2
// Explanation: We can remove one occurrence of 12, after which all numbers will
// become distinct.
// Then we can delete any two numbers which will leave us 2 distinct numbers in
// the result.
//
// Example 3:
// Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
// Expected Output: 3
// Explanation: We can remove one occurrence of '4' to get three distinct
// numbers 1, 2 and 4.

pub fn find_maximum_distinct_elements(nums: &[i32], k: i32) -> i32 {
    let mut k = k;
    let mut distinct_elements_count = 0;

    // Find the frequency of each number
    let mut num_frequency_map: HashMap<i32, i32> = HashMap::new();
    for &num in nums {
        *num_frequency_map.entry(num).or_insert(0) += 1;
    }

    // a min heap of the frequencies
    let mut min_heap = BinaryHeap::new();

    // Insert all numbers with frequency greater than '1' into the min-heap
    for &freq in num_frequency_map.values() {
        if freq == 1 {
            distinct_elements_count += 1;
        } else {
            min_heap.push(Reverse(freq));
        }
    }

    // Following a greedy approach, try removing the least frequent numbers
    // first from the min-heap
    while k > 0 {
        let Some(Reverse(frequency)) = min_heap.pop() else {
            break;
        };
        // To make an element distinct, we need to remove all of its
        // occurrences except one
        k -= frequency - 1;
        if k >= 0 {
            distinct_elements_count += 1;
        }
    }

    // If k > 0, this means we have to remove some distinct numbers
    if k > 0 {
        distinct_elements_count -= k;
    }

    distinct_elements_count
}
