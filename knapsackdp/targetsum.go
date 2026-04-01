package knapsackdp

// You are given a set of positive numbers and a target sum ‘S’.
// Each number should be assigned either a ‘+’ or ‘-’ sign.
// We need to find the total ways to assign symbols to make the sum of the numbers equal to the target ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=1
// Output: 3
// Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}
//
// Example 2:
// Input: {1, 2, 7, 1}, S=9
// Output: 2
// Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} & {-1+2+7+1}

func findTargetSubsets(num []int, str int) int {
	totalSum := 0
	for _, n := range num {
		totalSum += n
	}

	if totalSum < str || (str+totalSum)%2 == 1 {
		return 0
	}

	return countSets(num, (str+totalSum)/2)
}

func countSets(num []int, sum int) int {
	n := len(num)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, sum+1)
	}

	for i := range n {
		dp[i][0] = 1
	}

	for str := 1; str <= sum; str++ {
		if num[0] == str {
			dp[0][str] = 1
		} else {
			dp[0][str] = 0
		}
	}

	for i := 1; i < n; i++ {
		for str := 1; str <= sum; str++ {
			dp[i][str] = dp[i-1][str]
			if str >= num[i] {
				dp[i][str] += dp[i-1][str-num[i]]
			}
		}
	}

	return dp[n-1][sum]
}
