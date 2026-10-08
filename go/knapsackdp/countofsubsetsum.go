package knapsackdp

// Given a set of positive numbers,
// find the total number of subsets whose sum is equal to a given number ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=4
// Output: 3
// The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
// Note that we have two similar sets {1, 3}, because we have two '1' in our input.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}, S=9
// Output: 3
// The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}

func countSubsets(num []int, sum int) int {
	return countSubsetsRecursive(num, sum, 0)
}

func countSubsetsRecursive(num []int, sum int, currentIndex int) int {
	// base checks
	if sum == 0 {
		return 1
	}

	if len(num) == 0 || currentIndex >= len(num) {
		return 0
	}

	// recursive call after selecting the number at the currentIndex
	// if the number at currentIndex exceeds the sum, we shouldn't process this
	var sum1 int
	if num[currentIndex] <= sum {
		sum1 = countSubsetsRecursive(num, sum-num[currentIndex], currentIndex+1)
	}

	// recursive call after excluding the number at the currentIndex
	sum2 := countSubsetsRecursive(num, sum, currentIndex+1)

	return sum1 + sum2
}
