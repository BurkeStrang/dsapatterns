package hashmaps

import "math"

// Given a string, determine the maximum number of times the word "balloon" can be formed using the characters from the string.
// Each character in the string can be used only once.
//
// Example 1:
// Input: "balloonballoon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice from the given string.
//
// Example 2:
// Input: "bbaall"
// Expected Output: 0
// Justification: The word "balloon" cannot be formed from the given string as we are missing the character 'o' twice.
//
// Example 3:
// Input: "balloonballoooon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice, even though there are extra 'o' characters.
//
// Constraints:
// 1 <= text.length <= 104
// text consists of lower case English letters only.

func  maxNumberOfBalloons(text string) int {
	// Create a map to store character frequencies
	charCount := make(map[rune]int)

	// Populate the map with character frequencies from the string
	for _, c := range text {
		charCount[c]++
	}

	minCount := math.MaxInt // Max int value
	// Calculate the maximum number of times "balloon" can be formed
	minCount = min(minCount, charCount['b'])
	minCount = min(minCount, charCount['a'])
	minCount = min(minCount, charCount['l']/2)
	minCount = min(minCount, charCount['o']/2)
	minCount = min(minCount, charCount['n'])

	return minCount
}
