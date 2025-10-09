package monotonicstack

import "strings"

// Given a non-negative integer represented as a string num and an integer k,
// delete k digits from num to obtain the smallest possible integer.
// Return this minimum possible integer as a string.
//
// Examples
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: The digits removed are 4, 3, and 2 forming the new number 1219 which is the smallest.
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Removing the leading 1 forms the smallest number 200.
//
// Input: num = "1901042", k = 4
// Output: "2"
// Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest possible.
//
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

func removeKdigits(num string, k int) string {
	var stack []rune

	for _, digit := range num {
		for k > 0 && len(stack) > 0 && stack[len(stack)-1] > digit {
			stack = stack[:len(stack)-1]
			k--
		}
		stack = append(stack, digit)
	}

	// Truncate the remaining K digits
	for i := 0; i < k; i++ {
		stack = stack[:len(stack)-1]
	}

	// Convert Stack to String
	var sb strings.Builder
	for _, v := range stack {
		sb.WriteRune(v)
	}

	// Remove any leading zeros
	result := sb.String()
	for len(result) > 1 && result[0] == '0' {
		result = result[1:]
	}

	// If the String is empty return "0"
	if len(result) == 0 {
		return "0"
	}
	return result
}
