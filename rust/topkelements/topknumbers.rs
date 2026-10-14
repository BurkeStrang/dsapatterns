use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

// findKLargestNumbers - keeps all comments same and method name same

pub fn find_k_largest_numbers(nums: &[i32], k: usize) -> Vec<i32> {
    // BinaryHeap is a max heap, so wrap the numbers in Reverse to get a min
    // heap
    let mut min_heap = BinaryHeap::new();

    // put first 'K' numbers in the min heap
    for &num in &nums[..k] {
        min_heap.push(Reverse(num));
    }

    // go through the remaining numbers of the array, if the number from the
    // array is bigger than the top (smallest) number of the min-heap, remove
    // the top number from heap and add the number from array
    for &num in &nums[k..] {
        if num > min_heap.peek().unwrap().0 {
            min_heap.pop();
            min_heap.push(Reverse(num));
        }
    }

    // the heap has the top 'K' numbers, return them in a list
    min_heap.into_iter().map(|Reverse(num)| num).collect()
}
