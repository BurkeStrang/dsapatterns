package fibnum

// Given a staircase with ‘n’ steps and an array of 'n' numbers representing the fee that you have to pay if you take the step.
// Implement a method to calculate the minimum fee required to reach the top of the staircase (beyond the top-most step).
// At every step, you have an option to take either 1 step, 2 steps, or 3 steps.
// You should assume that you are standing at the first step.
//
// Example 1:
// Number of stairs (n) : 6
// Fee: {1,2,5,2,1,2}
// Output: 3
// Explanation: Starting from index '0', we can reach the top through: 0->3->top
// The total fee we have to pay will be (1+2).
//
// Example 2:
// Number of stairs (n): 4
// Fee: {2,3,4,5}
// Output: 5
// Explanation: Starting from index '0', we can reach the top through: 0->1->top
// The total fee we have to pay will be (2+3).

func findMinFee(fee []int) int {
	return findMinFeeRecursive(fee, 0)
}

func findMinFeeRecursive(fee []int, currentIndex int) int {
	if currentIndex > len(fee)-1 {
		return 0
	}

	// if we take 1 step, we are left with 'n-1' steps;
	take1Step := findMinFeeRecursive(fee, currentIndex+1)
	// similarly, if we took 2 steps, we are left with 'n-2' steps;
	take2Step := findMinFeeRecursive(fee, currentIndex+2)
	// if we took 3 steps, we are left with 'n-3' steps;
	take3Step := findMinFeeRecursive(fee, currentIndex+3)

	min := take1Step
	if take2Step < min {
		min = take2Step
	}
	if take3Step < min {
		min = take3Step
	}

	return min + fee[currentIndex]
}
