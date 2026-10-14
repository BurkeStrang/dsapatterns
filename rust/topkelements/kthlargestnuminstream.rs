use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Design a class to efficiently find the Kth largest element in a stream of
// numbers.
// The class should have the following two things:
// The constructor of the class should accept an integer array containing
// initial numbers from the stream and an integer ‘K’.
// The class should expose a function add(int num) which will store the given
// number and return the Kth largest number.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 4
// 1. Calling add(6) should return '5'.
// 2. Calling add(13) should return '6'.
// 2. Calling add(4) should still return '6'.

pub struct KthLargest {
    // a min heap holding the 'k' largest numbers seen so far
    min_heap: BinaryHeap<Reverse<i32>>,
    k: usize, // The value of 'k'
}

impl KthLargest {
    pub fn new(nums: &[i32], k: usize) -> Self {
        let mut result = KthLargest {
            min_heap: BinaryHeap::new(),
            k,
        };
        for &num in nums {
            result.add(num);
        }
        result
    }

    pub fn add(&mut self, num: i32) -> i32 {
        self.min_heap.push(Reverse(num));

        if self.min_heap.len() > self.k {
            self.min_heap.pop();
        }

        self.min_heap.peek().unwrap().0
    }
}
