package topkelements

import "sort"

// Given a string,
// find if its letters can be rearranged in such a way that no two same characters come next to each other.
//
// Example 1:
// Input: "aappp"
// Output: "papap"
// Explanation: In "papap", none of the repeating characters come next to each other.
//
// Example 2:
// Input: "Programming"
// Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
// Explanation: None of the repeating characters come next to each other.
//
// Example 3:
// Input: "aapa"
// Output: ""
// Explanation: In all arrangements of "aapa", atleast two 'a' will come together e.g., "apaa", "paaa".

func rearrangeString(str string) string {
	charFrequencyMap := make(map[byte]int)
	for i := 0; i < len(str); i++ {
		charFrequencyMap[str[i]]++
	}

	type CharFrequency struct {
		char  byte
		count int
	}
	charFrequencies := make([]CharFrequency, len(charFrequencyMap))

	i := 0
	for char, count := range charFrequencyMap {
		charFrequencies[i] = CharFrequency{char, count}
		i++
	}

	sort.Slice(charFrequencies, func(i, j int) bool {
		return charFrequencies[i].count > charFrequencies[j].count
	})

	resultString := make([]byte, len(str))
	index := 0
	var previousChar byte

	for len(charFrequencies) > 0 {
		currentChar := charFrequencies[0].char
		count := charFrequencies[0].count
		charFrequencies = charFrequencies[1:]

		// Check if the previous character can be added back to the list
		if previousChar != 0 && charFrequencyMap[previousChar] > 0 {
			charFrequencies = append(charFrequencies, CharFrequency{previousChar, charFrequencyMap[previousChar]})
		}

		// Append the current character to the result string and decrement its count
		resultString[index] = currentChar
		index++
		charFrequencyMap[currentChar]--
		previousChar = currentChar

		// Sort the charFrequencies to maintain the heap property
		sort.Slice(charFrequencies, func(i, j int) bool {
			return charFrequencies[i].count > charFrequencies[j].count
		})

		// If all characters are used up, break the loop
		if count == 1 && len(charFrequencies) == 0 {
			break
		}
	}

	// If we were successful in appending all the characters to the result string, return it
	if index == len(str) {
		return string(resultString)
	}
	return ""
}
