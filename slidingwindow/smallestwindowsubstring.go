package slidingwindow

// Given a string and a pattern, find the smallest substring in the given string which has all the character occurrences of the given pattern.
//
// Example 1:
// Input: String="aabdec", Pattern="abc"
// Output: "abdec"
// Explanation: The smallest substring having all characters of the pattern is "abdec"
//
// Example 2:
// Input: String="aabdec", Pattern="abac"
// Output: "aabdec"
// Explanation: The smallest substring having all characters occurrences of the pattern is "aabdec"
//
// Example 3:
// Input: String="abdbca", Pattern="abc"
// Output: "bca"
// Explanation: The smallest substring having all characters of the pattern is "bca".
//
// Example 4:
// Input: String="adcad", Pattern="abc"
// Output: ""
// Explanation: No substring in the given string has all characters of the pattern
// Constraints:
//
// m == String.length
// n == Pattern.length
// 1 <= m, n <= 105
// String and Pattern consist of uppercase and lowercase English letters.

func findSubstring(str string, pattern string) string {
	windowStart, matched, minLength, subStrStart := 0, 0, len(str)+1, 0
	charFrequencyMap := make(map[rune]int)

	for _, chr := range pattern {
		charFrequencyMap[chr]++
	}

	// try to extend the range [windowStart, windowEnd]
	for windowEnd, rightChar := range str {
		if _, ok := charFrequencyMap[rightChar]; ok {
			charFrequencyMap[rightChar]--
			if charFrequencyMap[rightChar] >= 0 {
				matched++
			}
		}

		// shrink the window if we can, finish as soon as we remove a matched character
		for matched == len(pattern) {
			if minLength > windowEnd-windowStart+1 {
				minLength = windowEnd - windowStart + 1
				subStrStart = windowStart
			}

			leftChar := rune(str[windowStart])
			windowStart++
			if _, ok := charFrequencyMap[leftChar]; ok {
				// note that we could have redundant matching characters, therefore we'll
				// decrement the matched count only when a useful occurrence of a matched
				// character is going out of the window
				if charFrequencyMap[leftChar] == 0 {
					matched--
				}
				charFrequencyMap[leftChar]++
			}
		}
	}

	if minLength > len(str) {
		return ""
	}
	return str[subStrStart : subStrStart+minLength]
}
