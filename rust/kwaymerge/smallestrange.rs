use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given ‘M’ sorted arrays, find the smallest range that includes at least one
// number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

pub fn find_smallest_range(lists: &[Vec<i32>]) -> [i32; 2] {
    // a min heap of (number, array index, element index); tuples compare
    // field by field, so the smallest number is on top
    let mut min_heap = BinaryHeap::new();

    let mut range_start = 0;
    let mut range_end = i32::MAX;
    let mut current_max_number = i32::MIN;

    // put the 1st element of each array in the min heap
    for (i, list) in lists.iter().enumerate() {
        if let Some(&first) = list.first() {
            min_heap.push(Reverse((first, i, 0)));
            current_max_number = current_max_number.max(first);
        }
    }

    // take the smallest (top) element form the min heap, if it gives us
    // smaller range, update the ranges; if the array of the top element has
    // more elements, insert the next element in the heap.
    // we stop as soon as one of the arrays has run out, the heap then holds
    // fewer numbers than there are arrays
    while min_heap.len() == lists.len() {
        let Reverse((num, array_index, element_index)) =
            min_heap.pop().unwrap();
        // widen to i64, the gap between the starting ends overflows an i32
        let current_range = i64::from(range_end) - i64::from(range_start);
        if current_range > i64::from(current_max_number) - i64::from(num) {
            range_start = num;
            range_end = current_max_number;
        }

        let element_index = element_index + 1;
        if let Some(&next) = lists[array_index].get(element_index) {
            min_heap.push(Reverse((next, array_index, element_index)));
            current_max_number = current_max_number.max(next);
        }
    }

    [range_start, range_end]
}
