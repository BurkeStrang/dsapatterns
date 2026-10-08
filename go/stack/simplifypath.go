package stack

import "strings"

// Given an absolute file path in a Unix-style file system,
// simplify it by converting ".." to the previous directory and removing any "." or multiple slashes.
// The resulting string should represent the shortest absolute path.
//
// Example 1
// Input: path = "/a//b////c/d//././/.."
// Expected Output: "/a/b/c"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// "." refers to the current directory and is ignored.
// ".." moves up one directory, so "d" is removed.
// The simplified path is "/a/b/c".
//
// Example 2
// Input: path = "/../"
// Expected Output: "/"
// Explanation:
// ".." moves up one directory, but we are already at the root ("/"), so nothing happens.
// The final simplified path remains "/".
//
// Example 3
// Input: path = "/home//foo/"
// Expected Output: "/home/foo"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// The final simplified path is "/home/foo".
//
// Constraints:
// 1 <= path.length <= 3000
// path consists of English letters, digits, period '.', slash '/' or '_'.
// path is a valid absolute Unix path.

func simplifyPath(path string) string {
	// Create a stack to store the simplified path components
	var stack []string

	// Split the input path string using '/' as a delimiter
	for _, p := range strings.Split(path, "/") {
		switch {
		case p == "..":
			// If the component is '..', pop the last component from the stack
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		case p != "" && p != ".":
			// If the component is not empty and not '.', push it onto the stack
			stack = append(stack, p)
		}
	}

	// Reconstruct the simplified path by joining components from the stack
	return "/" + strings.Join(stack, "/")
}
