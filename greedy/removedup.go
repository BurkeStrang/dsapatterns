package greedy

// Given a string s,
// remove all duplicate letters from the input string while maintaining the original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all possible results.
// A string is in the smallest lexicographical order if it appears first in a dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc strings.
// The final answer is 'abc', which is the smallest lexicographical string without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the smallest possible string without duplicate characters.

func removeDuplicateLetters(s string) string {
	count := make(map[rune]int)
	present := make(map[rune]bool)
	var result []rune

	// Count the frequency of each character
	for _, c := range s {
		count[c]++
	}

	for _, c := range s {
		if !present[c] {
			// Ensure smallest lexicographical order based off conditions of:
			// Has Result
			// Is Smaller
			// Can Remove Last
			for len(result) > 0 && c < result[len(result)-1] && count[result[len(result)-1]] > 0 {
				delete(present, result[len(result)-1])
				result = result[:len(result)-1]
			}
			result = append(result, c)
			present[c] = true
		}
		count[c]-- // Decrease the frequency
	}

	return string(result)
}
