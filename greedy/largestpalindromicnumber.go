package greedy

import "strings"

// Given a string s containing 0 to 9 digits, create the largest possible palindromic number using the string characters.
// It should not contain leading zeroes.
// A palindromic number reads the same backward as forward.
// If it's not possible to form such a number using all digits of the given string, you can skip some of them.
//
// Example 1
// Input: s = "323211444"
// Expected Output: "432141234"
// Justification: This is the largest palindromic number that can be formed from the given digits.
//
// Example 2
// Input: s = "998877"
// Expected Output: "987789"
// Justification: "987789" is the largest palindrome that can be formed.
//
// Example 3
// Input: s = "54321"
// Expected Output: "5"
// Justification: Only "5" can form a valid palindromic number as other digits cannot be paired.

func largestPalindromic(s string) string {
	var firstHalf strings.Builder // StringBuilder to store first half of the palindrome
	frequency := make([]int, 10)  // Frequency array for digits 0-9

	// Count the frequency of each digit in the input number
	for i := 0; i < len(s); i++ {
		val := int(s[i] - '0')
		frequency[val]++
	}

	middle := -1 // Variable to store the middle digit if needed

	// Iterate from the highest digit (9) to the lowest (0)
	for i := 9; i >= 0; i-- {
		if frequency[i] != 0 && (i != 0 || firstHalf.Len() > 0) {
			count := frequency[i]
			for count > 1 {
				firstHalf.WriteRune(rune(i + '0')) // Append the digit to firstHalf
				count -= 2                         // Use two of the digit for the first half
			}
			if count == 1 && middle == -1 {
				middle = i // Assign the middle digit if it's the largest odd-count digit
			}
		}
	}

	secondHalf := reverseString(firstHalf.String()) // Create secondHalf as a reversed copy of firstHalf
	if middle != -1 {                               // Append the middle digit if it exists
		firstHalf.WriteRune(rune(middle + '0'))
	}
	firstHalf.WriteString(secondHalf) // Append the reversed first half to firstHalf

	if firstHalf.Len() > 0 {
		return firstHalf.String() // Return the final palindrome or "0"
	}
	return "0"
}

func reverseString(s string) string {
	runes := []rune(s)
	for left, right := 0, len(runes)-1; left < right; left, right = left+1, right-1 {
		runes[left], runes[right] = runes[right], runes[left]
	}
	return string(runes)
}
