package subsets

func findSubsets(nums []int) [][]int {
	subsets := [][]int{}
	// start by adding the empty subset
	subsets = append(subsets, []int{})

	for _, currentNumber := range nums {
		// we will take all existing subsets and insert the current number in them to
		// create new subsets
		n := len(subsets)
		for i := range n {
			// create a new subset from the existing subset and insert the current
			// element to it
			set := make([]int, len(subsets[i]))
			copy(set, subsets[i])
			set = append(set, currentNumber)
			subsets = append(subsets, set)
		}
	}
	return subsets
}
