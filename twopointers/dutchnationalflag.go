package twopointers

// Given an array containing 0s, 1s and 2s, sort the array in-place.
// You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.
//
// The flag of the Netherlands consists of three colors: red, white and blue;
// and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.
//
// Examples
// Example 1
// Input: arr = [1, 0, 2, 1, 0]
// Output: [0, 0, 1, 1, 2]
// Explanation:
// All 0s are moved to the front, 1s in the middle, and 2s at the end.
// The relative order within each group doesn't matter.
// Example 2
// Input: arr= [2, 2, 0, 1, 2, 0]
// Output: [0, 0, 1, 2, 2, 2]
// Explanation:
// All 0s come first, followed by the 1, and then all 2s at the end.
// Sorting is done in-place without using extra space or counting.
// Constraints:
//
// n == arr.length
// 1 <= n <= 300
// arr[i] is either 0, 1, or 2.

func dutch(arr []int) []int {
	low, high := 0, len(arr)-1
	for i := 0; i <= high; {
		if arr[i] == 0 {
			swap(arr, i, low)
			// increment 'i' and 'low'
			i++
			low++
		} else if arr[i] == 1 {
			i++
		} else { // the case for arr[i] == 2
			swap(arr, i, high)
			// decrement 'high' only, after the swap the number at index 'i' could be 0, 1,
			// or 2
			high--
		}
	}
	return arr
}

// swap is a helper method to swap two elements in the array
func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}
