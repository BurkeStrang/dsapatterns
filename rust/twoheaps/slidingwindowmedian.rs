use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given an array of numbers and a number 'k', find the median of all the 'k'
// sized sub-arrays (or windows) of the array.
//
// Example 1:
// Input: nums=[1, 2, -1, 3, 5], k = 2
// Output: [1.5, 0.5, 1.0, 4.0]
//
// Example 2:
// Input: nums=[1, 2, -1, 3, 5], k = 3
// Output: [1.0, 2.0, 3.0]

#[derive(Default)]
struct Window {
    // the smaller half of the window, largest on top
    max_heap: BinaryHeap<i32>,
    // the larger half of the window, smallest on top; BinaryHeap is a
    // max-heap, hence the Reverse
    min_heap: BinaryHeap<Reverse<i32>>,
}

pub fn find_sliding_window_median(nums: &[i32], k: usize) -> Vec<f64> {
    let mut result = Vec::new();
    let mut window = Window::default();
    for i in 0..nums.len() {
        match window.max_heap.peek() {
            Some(&top) if top < nums[i] => {
                window.min_heap.push(Reverse(nums[i]))
            }
            _ => window.max_heap.push(nums[i]),
        }
        window.rebalance_heaps();

        // if we have at least 'k' elements in the sliding window
        if i + 1 >= k {
            // add the median to the result
            let max_top = *window.max_heap.peek().unwrap();
            if window.max_heap.len() == window.min_heap.len() {
                // we have even number of elements, take the average of middle
                // two elements
                let min_top = window.min_heap.peek().unwrap().0;
                result.push(f64::from(max_top + min_top) / 2.0);
            } else {
                // because max-heap will have one more element than the
                // min-heap
                result.push(f64::from(max_top));
            }

            // remove the element going out of the sliding window
            let element_to_be_removed = nums[i + 1 - k];
            if element_to_be_removed <= max_top {
                remove(&mut window.max_heap, &element_to_be_removed);
            } else {
                remove(&mut window.min_heap, &Reverse(element_to_be_removed));
            }
            window.rebalance_heaps();
        }
    }
    result
}

impl Window {
    fn rebalance_heaps(&mut self) {
        // either both the heaps will have equal number of elements or
        // max-heap will have one more element than the min-heap
        if self.max_heap.len() > self.min_heap.len() + 1 {
            let top = self.max_heap.pop().unwrap();
            self.min_heap.push(Reverse(top));
        } else if self.max_heap.len() < self.min_heap.len() {
            let Reverse(top) = self.min_heap.pop().unwrap();
            self.max_heap.push(top);
        }
    }
}

// remove takes one copy of the target out of the heap. BinaryHeap can't
// remove from the middle, so the heap is rebuilt without it.
fn remove<T: Ord>(heap: &mut BinaryHeap<T>, target: &T) {
    let mut items = std::mem::take(heap).into_vec();
    if let Some(index) = items.iter().position(|item| item == target) {
        items.swap_remove(index);
    }
    *heap = BinaryHeap::from(items);
}
