package monotonicstack

import "strings"

// You are given a string s and an integer k. Your task is to remove groups of identical,
// consecutive characters from the string such that each group has exactly k characters.
// The removal of groups should continue until it's no longer possible to make any more removals.
// The result should be the final version of the string after all possible removals have been made.
//
// Examples
//
// Input: s = "abbbaaca", k = 3
// Output: "ca"
// Explanation: First, we remove "bbb" to get "aaaca". Then, we remove "aaa" to get "ca".
//
// Input: s = "abbaccaa", k = 3
// Output: "abbaccaa"
// Explanation: There are no instances of 3 adjacent characters being the same.
//
// Input: s = "abbacccaa", k = 3
// Output: "abb"
// Explanation: First, we remove "ccc" to get "abbaaa". Then, we remove "aaa" to get "abb".
//
// Constraints:
// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

func removeDuplicatesII(s string, k int) string {
	var stack []stackElement // Initialize an empty stack to track characters and their counts.

	// Iterate through each character in the input string 's'.
	for _, c := range s {
		// If the stack is not empty and the current character is the same as the top of the stack.
		if len(stack) > 0 && stack[len(stack)-1].char == c {
			stack[len(stack)-1].count++ // Increment the count of the top character in the stack.
		} else {
			// Otherwise, push a new character-count pair onto the stack.
			stack = append(stack, stackElement{char: c, count: 1})
		}

		// If the count of the top character in the stack reaches 'k'.
		if stack[len(stack)-1].count == k {
			stack = stack[:len(stack)-1] // Remove it from the stack.
		}
	}

	var result strings.Builder // Initialize a string builder to construct the result string.

	// Iterate through the stack and reconstruct the string from the characters remaining in the stack.
	for _, element := range stack {
		result.WriteString(strings.Repeat(string(element.char), element.count))
	}

	return result.String() // Return the final result as a string.
}
