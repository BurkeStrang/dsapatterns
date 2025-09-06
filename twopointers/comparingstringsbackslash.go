package twopointers

// Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.
//
// Example 1:
//
// Input: str1="xy#z", str2="xzz#"
// Output: true
// Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
// Example 2:
//
// Input: str1="xy#z", str2="xyz#"
// Output: false
// Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
// Example 3:
//
// Input: str1="xp#", str2="xyz##"
// Output: true
// Explanation: After applying backspaces the strings become "x" and "x" respectively.
// In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
// Example 4:
//
// Input: str1="xywrrmp", str2="xywrrmu#p"
// Output: true
// Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
// Constraints:
//
// 1 <= str1.length, str2.length <= 200
// str1 and str2 only contain lowercase letters and '#' characters.

func compare(str1, str2 string) bool {
	index1 := len(str1) - 1
	index2 := len(str2) - 1

	for index1 >= 0 || index2 >= 0 {
		i1 := getNextValidCharIndex(str1, index1)
		i2 := getNextValidCharIndex(str2, index2)

		if i1 < 0 && i2 < 0 { // reached the end of both the strings
			return true
		}

		if i1 < 0 || i2 < 0 { // reached the end of one of the strings
			return false
		}

		if str1[i1] != str2[i2] { // check if the characters are equal
			return false
		}

		index1 = i1 - 1
		index2 = i2 - 1
	}

	return true
}

func getNextValidCharIndex(str string, index int) int {
	backspaceCount := 0
	for index >= 0 {
		if str[index] == '#' { // found a backspace character
			backspaceCount++
		} else if backspaceCount > 0 { // a non-backspace character
			backspaceCount--
		} else {
			break
		}

		index-- // skip a backspace or a valid character
	}
	return index
}
