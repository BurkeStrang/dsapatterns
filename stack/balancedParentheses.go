package stack

// Given a string s containing (, ), [, ], {, and } characters.
// Determine if a given string of parentheses is balanced.
// A string of parentheses is considered balanced if every opening parenthesis
// has a corresponding closing parenthesis in the correct order.
//
// Example 1:
// Input: String s = "{[()]}";
// Expected Output: true
// Explanation: The parentheses in this string are perfectly balanced. Every opening parenthesis '{', '[', '(' has a corresponding closing parenthesis '}', ']', ')' in the correct order.
//
// Example 2:
// Input: string s = "{[}]";
// Expected Output: false
// Explanation: The brackets are not balanced in this string. Although it contains the same number of opening and closing brackets for each type, they are not correctly ordered. The ']' closes '[' before '{' can be closed by '}', and similarly, '}' closes '{' before '[' can be closed by ']'.
//
// Example 3:
// Input: String s = "(]";
// Expected Output: false
// Explanation: The parentheses in this string are not balanced. Here, ')' does not have a matching opening parenthesis '(', and similarly, ']' does not have a matching opening bracket '['.
//
// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

func validParentheses(s1 string) bool {
	// Creating a stack to keep track of opening parentheses
	stack := []rune{}

	// Iterating through each character in the input string
	for _, c := range s1 {
		// If the character is an opening parenthesis, push it onto the stack
		if c == '(' || c == '{' || c == '[' {
			stack = append(stack, c)
		} else {
			// If stack is empty and we have a closing parenthesis, the string is not balanced
			if len(stack) == 0 {
				return false
			}
			// Pop the top character from the stack
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			// If the character is a closing parenthesis, check whether
			// it corresponds to the most recent opening parenthesis
			if c == ')' && top != '(' {
				return false
			}
			if c == '}' && top != '{' {
				return false
			}
			if c == ']' && top != '[' {
				return false
			}
		}
	}
	// If the stack is empty, all opening parentheses had a corresponding closing match
	return len(stack) == 0
}
