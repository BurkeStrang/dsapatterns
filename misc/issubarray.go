package misc

import "slices"

func isSubarray(nums []int, sub []int) bool {
	n := len(sub)

	for i := 0; i+n <= len(nums); i++ {
		if slices.Equal(nums[i:i+n], sub) {
			return true
		}
	}

	return false
}
