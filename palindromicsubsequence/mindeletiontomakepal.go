package palindromicsubsequence

// Given a string,
// find the minimum number of characters that we can remove to make it a palindrome.
//
// Example 1:
// Input: "abdbca"
// Output: 1
// Explanation: By removing "c", we get a palindrome "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Deleting "cp", we get a palindrome "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: We have to remove any two characters to get a palindrome, e.g. if we
// remove "pq", we get palindrome "r".

func findMinimumDeletions(st string) int {
	return len(st) - findLPSLen(st)
}

func findLPSLen(st string) int {
	dp := make([][]int, len(st))

	for i := range dp {
		dp[i] = make([]int, len(st))
		dp[i][i] = 1
	}

	for startIndex := len(st) - 1; startIndex >= 0; startIndex-- {
		for endIndex := startIndex + 1; endIndex < len(st); endIndex++ {
			if st[startIndex] == st[endIndex] {
				dp[startIndex][endIndex] = 2 + dp[startIndex+1][endIndex-1]
			} else {
				dp[startIndex][endIndex] = max(dp[startIndex+1][endIndex], dp[startIndex][endIndex-1])
			}
		}
	}

	return dp[0][len(st)-1]
}
