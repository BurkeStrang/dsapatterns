package slidingwindow

// Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter,
// find the length of the longest substring having the same letters after replacement.
//
// Example 1:
// Input: str="aabccbb", k=2
// Output: 5
// Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
//
// Example 2:
// Input: str="abbcb", k=1
// Output: 4
// Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
//
// Example 3:
// Input: str="abccde", k=1
// Output: 3
// Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
// Constraints:
//
// 1 <= str.length <=
// s consists of only lowercase English letters.
// 0 <= k <= s.length


func maxLengthReplace(str string, k int) int {
	windowStart, maxLength, maxRepeatLetterCount := 0, 0, 0
	letterFrequencyMap := make(map[rune]int)
	// try to extend the range [windowStart, windowEnd]
	for windowEnd, rightChar := range str {
		letterFrequencyMap[rightChar]++
		// we don't need to place the maxRepeatLetterCount under the below 'if', see the
		// explanation in the 'Solution' section above.
		if maxRepeatLetterCount < letterFrequencyMap[rightChar] {
			maxRepeatLetterCount = letterFrequencyMap[rightChar]
		}
		// current window size is from windowStart to windowEnd, overall we have a letter
		// which is repeating 'maxRepeatLetterCount' times, this means we can have a window
		// which has one letter repeating 'maxRepeatLetterCount' times and the remaining
		// letters we should replace. If the remaining letters are more than 'k', it is the
		// time to shrink the window as we are not allowed to replace more than 'k' letters
		if windowEnd-windowStart+1-maxRepeatLetterCount > k {
			leftChar := rune(str[windowStart])
			letterFrequencyMap[leftChar]--
			windowStart++
		}

		if maxLength < windowEnd-windowStart+1 {
			maxLength = windowEnd - windowStart + 1
		}
	}
	return maxLength
}
