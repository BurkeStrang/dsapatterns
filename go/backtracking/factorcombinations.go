package backtracking

// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

import "math"

func getFactors(n int) [][]int {
	return getAllFactors(n, 2, []int{}, [][]int{})
}

func getAllFactors(n, start int, curr []int, result [][]int) [][]int {
	for i := start; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			curr = append(curr, i)
			currCopy := make([]int, len(curr))
			copy(currCopy, curr)
			currCopy = append(currCopy, n/i)
			result = append(result, currCopy)
			result = getAllFactors(n/i, i, curr, result)
			curr = curr[:len(curr)-1]
		}
	}
	return result
}
