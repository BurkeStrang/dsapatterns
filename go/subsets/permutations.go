package subsets

func findPermutations(nums []int) [][]int {
	result := make([][]int, 0)
	permutations := make([][]int, 0)
	permutations = append(permutations, []int{})

	for _, currentNumber := range nums {
		// we will take all existing permutations and add the current number to create
		// new permutations
		n := len(permutations)
		for range n {
			oldPermutation := permutations[0]
			permutations = permutations[1:]
			// create a new permutation by adding the current number at every position
			for j := 0; j <= len(oldPermutation); j++ {
				newPermutation := make([]int, len(oldPermutation))
				copy(newPermutation, oldPermutation)
				newPermutation = append(newPermutation[:j], append([]int{currentNumber}, newPermutation[j:]...)...)
				if len(newPermutation) == len(nums) {
					result = append(result, newPermutation)
				} else {
					permutations = append(permutations, newPermutation)
				}
			}
		}
	}
	return result
}
