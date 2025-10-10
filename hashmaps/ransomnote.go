package hashmaps

// Given two strings,
// one representing a ransom note and the other representing the available letters from a magazine,
// determine if it's possible to construct the ransom note using only the letters from the magazine.
// Each letter from the magazine can be used only once.
//
// Example 1:
// Input: Ransom Note = "hello", Magazine = "hellworld"
// Expected Output: true
// Justification: The word "hello" can be constructed from the letters in "hellworld".
//
// Example 2:
// Input: Ransom Note = "notes", Magazine = "stoned"
// Expected Output: true
// Justification: The word "notes" can be fully constructed from "stoned" from its first 5 letters.
//
// Example 3:
// Input: Ransom Note = "apple", Magazine = "pale"
// Expected Output: false
// Justification: The word "apple" cannot be constructed from "pale" as we are missing one 'p'.
//
// Constraints:
// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

func canConstruct(ransomNote string, magazine string) bool {
	// Create a map to store character frequencies from the magazine
	charCount := make(map[rune]int)

	// Populate the map with character frequencies from the magazine
	for _, c := range magazine {
		charCount[c]++
	}

	// Check if the ransom note can be constructed
	for _, c := range ransomNote {
		if charCount[c] == 0 {
			return false
		}
		charCount[c]--
	}
	return true
}
