use std::collections::BinaryHeap;

// Given an array of intervals, find the next interval of each interval. In a
// list of intervals, for an interval 'i' its next interval 'j' will have the
// smallest 'start' greater than or equal to the 'end' of 'i'.
//
// Write a function to return an array containing indices of the next interval
// of each input interval. If there is no next interval of a given interval,
// return -1. It is given that none of the intervals have the same start
// point.

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Interval {
    pub start: i32,
    pub end: i32,
}

pub fn find_next_interval(intervals: &[Interval]) -> Vec<i32> {
    let n = intervals.len();
    // max-heaps of (start, index) and (end, index)
    let mut max_start_heap = BinaryHeap::new();
    let mut max_end_heap = BinaryHeap::new();
    let mut result = vec![-1; n]; // Default to -1

    // Initialize heaps
    for i in 0..n {
        max_start_heap.push((intervals[i].start, i));
        max_end_heap.push((intervals[i].end, i));
    }

    // Go through the intervals from the highest end to the lowest and find
    // the next interval of each
    while let Some((top_end, end_index)) = max_end_heap.pop() {
        // the last interval popped here is the one with the smallest start
        // that is still >= the end
        let mut top_start = None;
        while let Some(&(start, start_index)) = max_start_heap.peek() {
            if start < top_end {
                break;
            }
            top_start = Some((start, start_index));
            max_start_heap.pop();
        }

        if let Some((start, start_index)) = top_start {
            result[end_index] = start_index as i32;
            // Put it back as it could be next for other intervals
            max_start_heap.push((start, start_index));
        }
    }

    result
}
