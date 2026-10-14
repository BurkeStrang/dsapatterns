use std::collections::{BinaryHeap, HashMap};

// Design a class that simulates a Stack data structure,
// implementing the following two operations:
//
// push(int num): Pushes the number ‘num’ on the stack.
// pop(): Returns the most frequent number in the stack.
// If there is a tie, return the number which was pushed later.
//
// Example:
// After following push operations: push(1), push(2), push(3), push(2), push(1),
// push(2), push(5)
// 1. pop() should return 2, as it is the most frequent number
// 2. Next pop() should return 1
// 3. Next pop() should return 2

/// One push onto the stack: (frequency, sequence number, number). Tuples
/// compare field by field, so the max heap gives the most frequent number,
/// and among equally frequent ones the one pushed last.
type Element = (usize, usize, i32);

#[derive(Default)]
pub struct FrequencyStack {
    sequence_number: usize,
    max_heap: BinaryHeap<Element>,
    frequency_map: HashMap<i32, usize>,
}

impl FrequencyStack {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn push(&mut self, num: i32) {
        let frequency = self.frequency_map.entry(num).or_insert(0);
        *frequency += 1;
        self.max_heap.push((*frequency, self.sequence_number, num));
        self.sequence_number += 1;
    }

    pub fn pop(&mut self) -> Option<i32> {
        let (_, _, num) = self.max_heap.pop()?;

        // decrement the frequency or remove if this is the last number
        let frequency = self.frequency_map.get_mut(&num)?;
        if *frequency > 1 {
            *frequency -= 1;
        } else {
            self.frequency_map.remove(&num);
        }

        Some(num)
    }
}
