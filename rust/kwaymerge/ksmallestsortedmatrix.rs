use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given an N * N matrix where each row and column is sorted in ascending order,
// find the Kth smallest element in the matrix.
// Example 1:
// Input: Matrix=[
//     [2, 6, 8],
//     [3, 7, 10],
//     [5, 8, 11]
//   ],
//   K=5
// Output: 7
// Explanation: The 5th smallest number in the matrix is 7.

// find_kth_smallest_point finds the Kth smallest element in a matrix
pub fn find_kth_smallest_point(matrix: &[Vec<i32>], k: usize) -> i32 {
    // a min heap of (number, row, column); tuples compare field by field, so
    // the smallest number is on top
    let mut min_heap = BinaryHeap::new();

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (row, numbers) in matrix.iter().enumerate().take(k) {
        min_heap.push(Reverse((numbers[0], row, 0)));
    }

    // take the smallest (top) element form the min heap, if the running count
    // is equal to k return the number. if the row of the top element has more
    // elements, add the next element to the heap
    let mut number_count = 0;
    let mut result = 0;
    while let Some(Reverse((num, row, col))) = min_heap.pop() {
        result = num;
        number_count += 1;
        if number_count == k {
            break;
        }

        let col = col + 1;
        if let Some(&next) = matrix[row].get(col) {
            min_heap.push(Reverse((next, row, col)));
        }
    }

    result
}
