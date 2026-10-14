// Given an array, find the average of each subarray of ‘K’ contiguous
// elements in it.

pub fn find_averages(k: usize, arr: &[i32]) -> Vec<f64> {
    let mut result = Vec::with_capacity(arr.len() + 1 - k);
    let mut window_sum = 0;
    let mut window_start = 0;
    for window_end in 0..arr.len() {
        window_sum += arr[window_end]; // add the next element
        // slide the window, we don't need to slide if we've not hit the
        // required window size of 'k'
        if window_end + 1 >= k {
            result.push(f64::from(window_sum) / k as f64); // the average
            window_sum -= arr[window_start]; // subtract the element going out
            window_start += 1; // slide the window ahead
        }
    }
    result
}
