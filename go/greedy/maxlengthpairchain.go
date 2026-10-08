package greedy

import "sort"

// Given a collection of pairs where each pair contains two elements [a, b] and a < b,
// find the maximum length of a chain you can form using pairs.
// A pair [a, b] can follow another pair [c, d] in the chain if b < c.
// You can select pairs in any order and don't need to use all the given pairs.
//
// Example 1:
// Input: [[1,2], [3,4], [2,3]]
// Expected Output: 2
// Justification: The longest chain is [1,2] -> [3,4].
// The chain [1,2] -> [2,3] is invalid because 2 is not smaller than 2.
//
// Example 2:
// Input: [[5,6], [1,2], [8,9], [2,3]]
// Expected Output: 3
// Justification: The chain can be [1,2] -> [5,6] -> [8,9] or [2,3] -> [5,6] -> [8, 9].
//
// Example 3:
// Input: [[7,8], [5,6], [1,2], [3,5], [4,5], [2,3]]
// Expected Output: 3
// Justification: The longest possible chain is formed by chaining [1,2] -> [3,5] -> [7,8].

func findLongestChain(pairs [][]int) int {
	// Sort pairs based on their second element in ascending order
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i][1] < pairs[j][1]
	})

	currentEnd := -1 << 31 // Current end of the chain
	chainCount := 0        // Count of pairs in the chain

	// Iterate through the sorted pairs
	for _, pair := range pairs {
		// Check if the first element of the pair is greater than the current end
		if pair[0] > currentEnd {
			// Update the current end and increment the chain count
			currentEnd = pair[1]
			chainCount++
		}
	}

	return chainCount // Return the maximum chain length
}
