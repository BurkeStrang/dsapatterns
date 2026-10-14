// Given a positive integer n, write a function that returns its binary
// equivalent as a string.
// The function should not use any in-built binary conversion function.
//
// Example 1:
// Input: 2
// Output: "10"
// Explanation: The binary equivalent of 2 is 10.
//
// Example 2:
// Input: 7
// Output: "111"
// Explanation: The binary equivalent of 7 is 111.
//
// Example 3:
// Input: 18
// Output: "10010"
// Explanation: The binary equivalent of 18 is 10010.
//
// Constraints:
// 1 <= n <= 10^9

pub fn decimal_to_binary(mut num: u32) -> String {
    let mut stack = Vec::new(); // An empty stack to store binary digits.
    let mut sb = String::new(); // An empty string to build the result in.

    // Convert the decimal number to binary using a stack.
    while num > 0 {
        stack.push(num % 2); // Push the remainder (a binary digit).
        num /= 2; // Update num by dividing it by 2 (integer division).
    }

    // Pop binary digits from the stack and build the binary string.
    while let Some(digit) = stack.pop() {
        sb.push(if digit == 1 { '1' } else { '0' });
    }

    sb // Return the binary representation as a string.
}
