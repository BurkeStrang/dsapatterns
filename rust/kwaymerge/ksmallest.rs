use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
//
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
// Output: 4
// Explanation: The 5th smallest number among all the arrays is 4, this can be
// verified from
// the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7], K=3
// Output: 7
// Explanation: The 3rd smallest number among all the arrays is 7.

pub fn find_kth_smallest(lists: &[Vec<i32>], k: usize) -> i32 {
    // a min heap of (number, array index, element index); tuples compare
    // field by field, so the smallest number is on top
    let mut min_heap = BinaryHeap::new();

    // put the 1st element of each array in the min heap
    for (i, list) in lists.iter().enumerate() {
        if let Some(&first) = list.first() {
            min_heap.push(Reverse((first, i, 0)));
        }
    }

    // take the smallest (top) element form the min heap, if the running count
    // is equal to k return the number if the array of the top element has
    // more elements, add the next element to the heap
    let mut number_count = 0;
    let mut result = 0;
    while let Some(Reverse((num, array_index, element_index))) = min_heap.pop()
    {
        result = num;
        number_count += 1;
        if number_count == k {
            break;
        }

        let element_index = element_index + 1;
        if let Some(&next) = lists[array_index].get(element_index) {
            min_heap.push(Reverse((next, array_index, element_index)));
        }
    }

    result
}
