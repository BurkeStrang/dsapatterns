use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

#[derive(Debug, PartialEq, Eq)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

// merge merges the given lists into one sorted list.
pub fn merge(mut lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
    // a min heap of (value of the first node of a list, index of that list);
    // the nodes themselves stay in 'lists'
    let mut min_heap = BinaryHeap::new();

    // put the root of each list in the min heap
    for (i, root) in lists.iter().enumerate() {
        if let Some(node) = root {
            min_heap.push(Reverse((node.val, i)));
        }
    }

    // take the smallest (top) element form the min-heap and add it to the
    // result; if the top element has a next element add it to the heap
    let mut result_head = None;
    // the empty 'next' at the end of the result, where the next node goes
    let mut result_tail = &mut result_head;
    while let Some(Reverse((_, i))) = min_heap.pop() {
        // cut the first node off its list
        let mut node = lists[i].take().unwrap();
        lists[i] = node.next.take();

        if let Some(next) = &lists[i] {
            min_heap.push(Reverse((next.val, i)));
        }

        result_tail = &mut result_tail.insert(node).next;
    }

    result_head
}
