package hashmaps

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

func maxNumberOfBalloons(text string) int {
	freq := make(map[rune]int)
	for _, letter := range text {
		freq[letter]++
	}
	minResult := len(text)
	list := []rune{'b', 'a', 'l', 'o', 'n'}
	for _, letter := range list {
		if letter == 'l' || letter == 'o' {
			minResult = min(minResult, freq[letter]/2)
		} else {
			minResult = min(minResult, freq[letter])
		}
	}
	return minResult
}
