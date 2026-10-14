use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

pub fn find_top_k_frequent_numbers(nums: &[i32], k: usize) -> Vec<i32> {
    // Find the frequency of each number
    let mut num_frequency_map: HashMap<i32, usize> = HashMap::new();
    for &n in nums {
        *num_frequency_map.entry(n).or_insert(0) += 1;
    }

    // Create a min heap to store (frequency, number) entries
    let mut min_freq_heap = BinaryHeap::new();

    // Go through all numbers in num_frequency_map and push them into the
    // min heap. If the heap size is more than k, remove the smallest (top)
    // entry
    for (num, frequency) in num_frequency_map {
        min_freq_heap.push(Reverse((frequency, num)));
        if min_freq_heap.len() > k {
            min_freq_heap.pop();
        }
    }

    // Create a list of top k frequent numbers; the heap gives the least
    // frequent first, so fill the list from the back
    let mut top_numbers = vec![0; min_freq_heap.len()];
    for slot in top_numbers.iter_mut().rev() {
        let Reverse((_, num)) = min_freq_heap.pop().unwrap();
        *slot = num;
    }

    top_numbers
}
