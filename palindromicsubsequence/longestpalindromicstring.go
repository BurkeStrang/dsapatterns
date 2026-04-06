package palindromicsubsequence

// Given a string, find the length of its Longest Palindromic Substring (LPS).
// In a palindromic string, elements read the same backward and forward.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: LPS is "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

func findLPStringLength(st string) int {
	return isPalindrome(st, 0, len(st)-1)
}

func isPalindrome(st string, startIndex, endIndex int) int {
	if startIndex > endIndex {
		return 0
	}

	if startIndex == endIndex {
		return 1
	}

	if st[startIndex] == st[endIndex] {
		remainingLength := endIndex - startIndex - 1
		if remainingLength == isPalindrome(st, startIndex+1, endIndex-1) {
			return remainingLength + 2
		}
	}

	c1 := isPalindrome(st, startIndex+1, endIndex)
	c2 := isPalindrome(st, startIndex, endIndex-1)
	if c1 > c2 {
		return c1
	}
	return c2
}
