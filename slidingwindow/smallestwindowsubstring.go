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
	patternFreq := make(map[byte]int)
	for i := range pattern {
		patternFreq[pattern[i]]++
	}

	start, matched, minLen, subStrStart := 0, 0, len(str)+1, 0
	windowFreq := make(map[byte]int)

	for end := range len(str) {
		rightChar := str[end]
		windowFreq[rightChar]++
		if patternFreq[rightChar] > 0 && windowFreq[rightChar] <= patternFreq[rightChar] {
			matched++
		}

		for matched == len(pattern) {
			if end-start+1 < minLen {
				minLen = end - start + 1
				subStrStart = start
			}
			leftChar := str[start]
			windowFreq[leftChar]--
			if patternFreq[leftChar] > 0 && windowFreq[leftChar] < patternFreq[leftChar] {
				matched--
			}
			start++
		}
	}

	if minLen > len(str) {
		return ""
	}
	return str[subStrStart : subStrStart+minLen]
}
