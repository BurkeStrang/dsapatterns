package subsets

import "sort"

func finddupSubsets(nums []int) [][]int {
	// sort the numbers to handle duplicates
	sort.Ints(nums)
	subsets := [][]int{{}}
	startIndex, endIndex := 0, 0
	for i := range nums {
		startIndex = 0
		// if current and the previous elements are same, create new subsets only from the
		// subsets added in the previous step
		if i > 0 && nums[i] == nums[i-1] {
			startIndex = endIndex + 1
		}
		endIndex = len(subsets) - 1
		for j := startIndex; j <= endIndex; j++ {
			// create a new subset from the existing subset and add the current element to it
			set := make([]int, len(subsets[j]))
			copy(set, subsets[j])
			set = append(set, nums[i])
			subsets = append(subsets, set)
		}
	}
	return subsets
}
