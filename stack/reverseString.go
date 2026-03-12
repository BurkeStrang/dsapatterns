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

func reverseString(input string) string {
	reverseList := make([]rune, 0, len(input))
	stack := []rune(input)
	// pop all letters from stack to reverseList
	for len(stack) > 0 {
		reverseList = append(reverseList, stack[len(stack)-1])
		stack = stack[:len(stack)-1]
	}

	return string(reverseList)
}
