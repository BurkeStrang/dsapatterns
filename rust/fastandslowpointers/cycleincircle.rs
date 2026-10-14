// We are given an array containing positive and negative numbers. Suppose the
// array contains a number ‘M’ at a particular index.
// Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is
// negative move backwards ‘M’ indices.
// You should assume that the array is circular which means two things:
//
// If, while moving forward, we reach the end of the array, we will jump to the
// first element to continue the movement.
// If, while moving backward, we reach the beginning of the array, we will jump
// to the last element to continue the movement.
// Write a method to determine if the array has a cycle.
// The cycle should have more than one element and should follow one direction
// which means the cycle should not contain both forward and backward movements.
//
// Example 1:
//
// Input: [1, 2, -1, 2, 2]
// Output: true
// Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0
// Example 2:
//
// Input: [2, 2, -1, 2]
// Output: true
// Explanation: The array has a cycle among indices: 1 -> 3 -> 1
// Example 3:
//
// Input: [2, 1, -1, -2]
// Output: false
// Explanation: The array does not have any cycle.
// Constraints:
//
// 1 <= nums.length <= 5000
// `-1000 <= nums[i] <= 1000
// nums[i] != 0

pub fn loop_exists(arr: &[i32]) -> bool {
    for i in 0..arr.len() {
        let is_forward = arr[i] >= 0; // if we are moving forward or not
        let mut slow = Some(i);
        let mut fast = Some(i);

        // if slow or fast becomes None this means we can't find cycle for
        // this number
        loop {
            // move one step for slow pointer
            slow = slow.and_then(|s| find_next_index(arr, is_forward, s));
            // move two steps for fast pointer
            fast = fast.and_then(|f| find_next_index(arr, is_forward, f));
            fast = fast.and_then(|f| find_next_index(arr, is_forward, f));
            if slow.is_none() || fast.is_none() || slow == fast {
                break;
            }
        }

        if slow.is_some() && slow == fast {
            return true;
        }
    }
    false
}

fn find_next_index(
    arr: &[i32],
    is_forward: bool,
    current_index: usize,
) -> Option<usize> {
    let direction = arr[current_index] >= 0;
    if is_forward != direction {
        return None; // change in direction
    }

    // rem_euclid wraps around for negative numbers
    let len = arr.len() as i32;
    let next_index =
        (current_index as i32 + arr[current_index]).rem_euclid(len) as usize;

    // one element cycle
    if next_index == current_index {
        return None;
    }
    Some(next_index)
}
