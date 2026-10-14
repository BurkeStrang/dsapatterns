use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Design a class to calculate the median of a number stream. The class should
// have the following two methods:
//
// insert_num(num): stores the number in the class
// find_median(): returns the median of all numbers inserted in the class
//
// If the count of numbers inserted in the class is even, the median will be
// the average of the middle two numbers.

#[derive(Default)]
pub struct Median {
    // the smaller half of the numbers, largest on top
    max_heap: BinaryHeap<i32>,
    // the larger half of the numbers, smallest on top; BinaryHeap is a
    // max-heap, hence the Reverse
    min_heap: BinaryHeap<Reverse<i32>>,
}

impl Median {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn insert_num(&mut self, num: i32) {
        match self.max_heap.peek() {
            Some(&top) if top < num => self.min_heap.push(Reverse(num)),
            _ => self.max_heap.push(num),
        }

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

    pub fn find_median(&self) -> f64 {
        let max_top = f64::from(*self.max_heap.peek().unwrap());
        if self.max_heap.len() == self.min_heap.len() {
            // we have even number of elements, take the average of middle two
            // elements
            let min_top = f64::from(self.min_heap.peek().unwrap().0);
            return max_top / 2.0 + min_top / 2.0;
        }
        // because max-heap will have one more element than the min-heap
        max_top
    }
}
