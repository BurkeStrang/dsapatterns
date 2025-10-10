package hashmaps

// Given a string, determine the length of the longest palindrome that can be constructed using the characters from the string.
// Return the maximum possible length of the palindromic string.
//
// Examples:
//
// Input: "applepie"
// Expected Output: 5
// Justification: The longest palindrome that can be constructed from the string is "pepep", which has a length of 5. There are are other palindromes too but they all will be of length 5.
//
// Input: "aabbcc"
// Expected Output: 6
// Justification: We can form the palindrome "abccba" using the characters from the string, which has a length of 6.
//
// Input: "bananas"
// Expected Output: 5
// Justification: The longest palindrome that can be constructed from the string is "anana", which has a length of 5.
//
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.


func  longestPalindrome(s string) int {
	charFreq := make(map[byte]int)

	// Populate the map with character frequencies
	for i := 0; i < len(s); i++ {
		charFreq[s[i]]++
	}

	length := 0
	oddFound := false

	// Calculate the palindrome length
	for _, freq := range charFreq {
		if freq%2 == 0 {
			length += freq
		} else {
			length += freq - 1
			oddFound = true
		}
	}

	// Add the central character if any odd frequency was found
	if oddFound {
		length++
	}

	return length
}
