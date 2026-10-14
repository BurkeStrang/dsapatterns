use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from
// both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum
// larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

// find_k_largest_pairs finds k largest pairs.
pub fn find_k_largest_pairs(
    nums1: &[i32],
    nums2: &[i32],
    k: usize,
) -> Vec<[i32; 2]> {
    // a min heap of (sum of the pair, the pair), so the pair with the
    // smallest sum is on top
    let mut min_heap: BinaryHeap<Reverse<(i32, [i32; 2])>> = BinaryHeap::new();

    for &num1 in nums1.iter().take(k) {
        for &num2 in nums2.iter().take(k) {
            let sum = num1 + num2;
            if min_heap.len() < k {
                min_heap.push(Reverse((sum, [num1, num2])));
                continue;
            }

            // if the sum of the two numbers from the two arrays is smaller
            // than the smallest (top) element of the heap, we can 'break'
            // here.
            let Reverse((smallest_sum, _)) = *min_heap.peek().unwrap();
            if sum < smallest_sum {
                break;
            }

            // we've a pair with a larger sum, remove top and insert this pair
            // in heap
            min_heap.pop();
            min_heap.push(Reverse((sum, [num1, num2])));
        }
    }

    let mut result = Vec::with_capacity(min_heap.len());
    while let Some(Reverse((_, pair))) = min_heap.pop() {
        result.push(pair);
    }
    result
}
