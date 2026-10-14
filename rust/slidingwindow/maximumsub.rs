// Given an array of positive numbers and a positive number 'k,' find the
// maximum sum of any contiguous subarray of size 'k'.
//
// Example 1:
//
// Input: arr = [2, 1, 5, 1, 3, 2], k=3
// Output: 9
// Explanation: Subarray with maximum sum is [5, 1, 3].
// Example 2:
//
// Input: arr = [2, 3, 4, 1, 5], k=2
// Output: 7
// Explanation: Subarray with maximum sum is [3, 4].

pub fn find_max_sum_sub_array(k: usize, arr: &[i32]) -> i32 {
    let mut window_sum = 0;
    let mut max_sum = 0;
    let mut window_start = 0;
    for window_end in 0..arr.len() {
        window_sum += arr[window_end]; // add the next element
        // slide the window, no need to slide if we've not hit the window size
        // of 'k'
        if window_end + 1 >= k {
            max_sum = max_sum.max(window_sum);
            window_sum -= arr[window_start]; // subtract the element going out
            window_start += 1; // slide the window ahead
        }
    }
    max_sum
}
