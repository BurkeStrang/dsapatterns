package slidingwindow

// Given a string and a pattern, find all anagrams of the pattern in the given string.
// Every anagram is a permutation of a string.
// As we know, when we are not allowed to repeat characters while finding permutations of a string,
// we get  permutations (or anagrams) of a string having  characters. For example, here are the six anagrams of the string abc:
//
// abc
// acb
// bac
// bca
// cab
// cba
//
// Write a function to return a list of starting indices of the anagrams of the pattern in the given string.
//
// Example 1:
// Input: str="ppqp", pattern="pq"
// Output: [1, 2]
// Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
//
// Example 2:
// Input: str="abbcabc", pattern="abc"
// Output: [2, 3, 4]
// Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
//
// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// str and pattern consist of lowercase English letters.

func findStringAnagrams(str string, pattern string) []int {
	windowStart, matched := 0, 0
	charFrequencyMap := make(map[rune]int)
	for _, chr := range pattern {
		charFrequencyMap[chr]++
	}

	resultIndices := make([]int, 0)
	// our goal is to match all the characters from the map with the current window
	for windowEnd, rightChar := range str {
		// decrement the frequency of the matched character
		if _, ok := charFrequencyMap[rightChar]; ok {
			charFrequencyMap[rightChar]--
			if charFrequencyMap[rightChar] == 0 {
				matched++
			}
		}

		if matched == len(charFrequencyMap) { // have we found an anagram?
			resultIndices = append(resultIndices, windowStart)
		}

		if windowEnd >= len(pattern)-1 { // shrink the window
			leftChar := rune(str[windowStart])
			windowStart++
			if _, ok := charFrequencyMap[leftChar]; ok {
				if charFrequencyMap[leftChar] == 0 {
					matched-- // before putting the character back, decrement the matched count
				}
				// put the character back
				charFrequencyMap[leftChar]++
			}
		}
	}

	return resultIndices
}
