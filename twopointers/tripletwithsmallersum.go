package twopointers

import "sort"

func findTriplets(arr []int, target int) int {
	if len(arr) < 3 {
		return 0
	}

	sort.Ints(arr)
	count := 0
	for i := 0; i < len(arr)-2; i++ {
		count += getPair(arr, target-arr[i], i)
	}
	return count
}

// searchPair method as per the Java version
func getPair(arr []int, targetSum int, first int) int {
	count := 0
	left, right := first+1, len(arr)-1
	for left < right {
		if arr[left]+arr[right] < targetSum { // found the triplet
			// since arr[right] >= arr[left], therefore, we can replace arr[right] by any
			// number between left and right to get a sum less than the target sum
			count += right - left
			left++
		} else {
			right-- // we need a pair with a smaller sum
		}
	}
	return count
}
