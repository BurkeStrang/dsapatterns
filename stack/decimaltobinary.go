package stack

import "fmt"

// Given a positive integer n, write a function that returns its binary equivalent as a string.
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

func decimalToBinary(num int) string {
	stack := []int{} // Create an empty stack to store binary digits.
	sb := ""         // Initialize an empty string to build the binary representation.

	// Convert the decimal number to binary using a stack.
	for num > 0 {
		stack = append(stack, num%2) // Push the remainder of num%2 (binary digit) onto the stack.
		num /= 2                     // Update num by dividing it by 2 (integer division).
	}

	// Pop binary digits from the stack and build the binary string.
	for len(stack) > 0 {
		pop := stack[len(stack)-1]   // Pop the top element from the stack.
		stack = stack[:len(stack)-1] // Remove the popped element from the stack.
		sb += fmt.Sprintf("%d", pop) // Append the popped binary digit to the result string.
	}

	return sb // Return the binary representation as a string.
}
