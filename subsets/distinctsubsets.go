package subsets

// example1: [1,3] => [[], [1], [3], [1,3]]
// example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]

func findSubsets(nums []int) [][]int {
	subsets := [][]int{}

	// start by adding the empty subset
	subsets = append(subsets, []int{})
	// subsets = [[]]

	for _, currentNumber := range nums {
		// ===== Iteration 1 =====
		// currentNumber = 1

		// ===== Iteration 2 =====
		// currentNumber = 3

		// we will take all existing subsets and insert the current number in them
		n := len(subsets)

		for i := range n {

			// -------- EXAMPLE WALKTHROUGH --------
			// INPUT: nums = [1,3]

			// Before any loops:
			// subsets = [[]]

			// ===============================
			// OUTER LOOP 1
			// currentNumber = 1
			// n = 1
			//
			// INNER LOOP:
			//
			// i = 0
			// subsets[i] = []
			// set (copy of subsets[i]) = []
			// after append currentNumber:
			// set = [1]
			//
			// subsets becomes:
			// [[], [1]]
			// ===============================

			// ===============================
			// OUTER LOOP 2
			// currentNumber = 3
			// n = 2  (because subsets now has 2 items)
			//
			// INNER LOOP:
			//
			// i = 0
			// subsets[0] = []
			// set = []
			// after append:
			// set = [3]
			//
			// subsets becomes:
			// [[], [1], [3]]
			//
			// i = 1
			// subsets[1] = [1]
			// set = [1]
			// after append:
			// set = [1,3]
			//
			// subsets becomes:
			// [[], [1], [3], [1,3]]
			// ===============================

			set := make([]int, len(subsets[i]))
			copy(set, subsets[i])
			set = append(set, currentNumber)
			subsets = append(subsets, set)
		}
	}
	return subsets
}
