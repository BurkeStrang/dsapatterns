use std::cmp::{Ordering, Reverse};
use std::collections::BinaryHeap;

// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

pub fn find_closest_elements(arr: &[i32], k: usize, x: i32) -> Vec<i32> {
    let index = binary_search(arr, x);
    // 'low' should not be less than zero
    let low = index.saturating_sub(k);
    // 'high' should not be greater the size of the array
    let high = (index + k).min(arr.len() - 1);

    // a min heap of (absolute difference from 'x', index)
    let mut min_heap = BinaryHeap::new();
    // add all candidate elements to the min heap, sorted by their absolute
    // difference from 'x'
    for i in low..=high {
        min_heap.push(Reverse(((arr[i] - x).abs(), i)));
    }

    // we need the top 'k' elements having the smallest difference from 'x'
    let mut result = Vec::new();
    for _ in 0..k {
        let Some(Reverse((_, i))) = min_heap.pop() else {
            break;
        };
        result.push(arr[i]);
    }

    result.sort_unstable();
    result
}

// binary_search returns the index of the target, or of the number closest to
// it from below when the target is not in the array
fn binary_search(arr: &[i32], target: i32) -> usize {
    // search the half-open range [low, high), so 'high' never goes below 0
    let mut low = 0;
    let mut high = arr.len();
    while low < high {
        let mid = low + (high - low) / 2;
        match arr[mid].cmp(&target) {
            Ordering::Equal => return mid,
            Ordering::Less => low = mid + 1,
            Ordering::Greater => high = mid,
        }
    }
    low.saturating_sub(1)
}
