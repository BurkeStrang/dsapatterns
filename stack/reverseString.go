package stack

// Given a string, write a function that uses a stack to reverse the string. The function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.


func  reverseString(input string) string {
	// Create a stack using a slice
	stack := []rune(input)

	// Use a slice to collect reversed characters
	reversedList := make([]rune, 0, len(input))

	// Pop characters from the stack and add to the slice
	for len(stack) > 0 {
		// Pop last element
		reversedList = append(reversedList, stack[len(stack)-1])
		stack = stack[:len(stack)-1]
	}

	// Convert slice to string
	return string(reversedList)
}
