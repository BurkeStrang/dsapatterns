// In a non-empty array of integers,
// every number appears twice except for one,
// find that single number. Use 0(1) space
// and O(n) time complexity. You can
// modify the input array.
//
// Example 1:
// Input: 1, 4, 2, 1, 3, 2, 3
// Output: 4
//
// Example 2:
// Input: 7, 9, 7
// Output: 9

pub fn find_single_number(arr: &[i32]) -> i32 {
    let mut num = 0; // Initialize a variable to store the result
    for i in 0..arr.len() {
        num ^= arr[i]; // XOR operation to find the single number
    }
    num
}
