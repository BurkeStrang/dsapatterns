package hashmaps
// Given a string, identify the position of the first character that appears only once in the string.
// If no such character exists, return -1.
//
// Example 1:
// Input: "apple"
// Expected Output: 0
// Justification: The first character 'a' appears only once in the string and is the first character.
//
// Example 2:
// Input: "abcab"
// Expected Output: 2
// Justification: The first character that appears only once is 'c' and its position is 2.
//
// Example 3:
// Input: "abab"
// Expected Output: -1
// Justification: There is no character in the string that appears only once.
//
// Constraints:
// 1 <= s.length <= 105
// s consists of only lowercase English letters.


func firstUniqChar(sStr string) int {
    // Create a hashmap to store the frequency of each character
    freq := make(map[rune]int)

    // Traverse the string to populate the hashmap with character frequencies
    for _, c := range sStr {
        freq[c]++
    }

    // Traverse the string again to find the first unique character
    for i, c := range sStr {
        if freq[c] == 1 {
            return i
        }
    }

    // If no unique character is found, return -1
    return -1
}
