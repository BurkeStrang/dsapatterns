package topkelements

import (
	"sort"
)

// Given a string, sort it based on the decreasing frequency of its characters.
//
// Example 1:
// Input: "Programming"
// Output: "rrggmmPiano"
// Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
//
// Example 2:
// Input: "abcbab"
// Output: "bbbaac"
// Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared only once.

func sortCharacterByFrequency(str string) string {
	// Find the frequency of each character
	characterFrequencyMap := make(map[rune]int)
	for _, chr := range str {
		characterFrequencyMap[chr]++
	}

	// Create a slice of character-frequency pairs for sorting
	characterFrequencyPairs := make([]struct {
		character rune
		frequency int
	}, 0)

	for chr, freq := range characterFrequencyMap {
		characterFrequencyPairs = append(characterFrequencyPairs, struct {
			character rune
			frequency int
		}{chr, freq})
	}

	// Sort the character-frequency pairs by frequency in descending order
	sort.Slice(characterFrequencyPairs, func(i, j int) bool {
		return characterFrequencyPairs[i].frequency > characterFrequencyPairs[j].frequency
	})

	// Build a string, appending the most occurring characters first
	sortedString := make([]rune, 0, len(str))
	for _, pair := range characterFrequencyPairs {
		for i := 0; i < pair.frequency; i++ {
			sortedString = append(sortedString, pair.character)
		}
	}

	return string(sortedString)
}
