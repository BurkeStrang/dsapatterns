package fibnum

import "math"

// Given an array of positive numbers,
// where each element represents the max number of jumps that can be made forward from that element,
// write a program to find the minimum number of jumps needed to reach the end of the array
// (starting from the first element).
// If an element is 0, then we cannot move through that element.
//
// Example 1:
// Input = {2,1,1,1,4}
// Output = 3
// Explanation: Starting from index '0', we can reach the last index through: 0->2->3->4
//
// Example 2:
// Input = {1,1,3,6,9,3,0,1,3}
// Output = 4
// Explanation: Starting from index '0', we can reach the last index through: 0->1->2->3->8

func countMinJumps(jumps []int) int {
	return countMinJumpsRecursive(jumps, 0)
}

func countMinJumpsRecursive(jumps []int, currentIndex int) int {
	if currentIndex == len(jumps)-1 {
		return 0
	}

	if jumps[currentIndex] == 0 {
		return math.MaxInt32
	}

	totalJumps := math.MaxInt32
	start := currentIndex + 1
	end := currentIndex + jumps[currentIndex]
	for start < len(jumps) && start <= end {
		minJumps := countMinJumpsRecursive(jumps, start)
		if minJumps != math.MaxInt32 {
			totalJumps = int(min(totalJumps, minJumps+1))
		}
		start++
	}
	return totalJumps
}
