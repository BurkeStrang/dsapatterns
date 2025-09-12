package slidingwindow

// Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s,
// find the length of the longest contiguous subarray having all 1s.
//
// Example 1:
// Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
// Output: 6
// Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
//
// Example 2:
// Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
// Output: 9
// Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.
//
// Example 3:
// Input: Array=[1, 0, 0, 1, 1, 0, 1, 1], k=2
// Output: 6
// Explanation: By flipping 0 at the second and fifth index in the list, we get [1, 0, 1, 1, 1, 1, 1, 1], which has 6 consecutive 1s.
// Constraints:
//
// 1 <= arr.length <=
// arr[i] is either 0 or 1.
// 0 <= k <= nums.length

func maxOnesLength(arr []int, k int) int {
	windowStart, maxLength, maxOnesCount := 0, 0, 0

	for windowEnd := range arr {
		if arr[windowEnd] == 1 {
			maxOnesCount++
		}
		// current window size is from windowStart to windowEnd, overall we have a maximum
		// of 1s repeating a maximum of 'maxOnesCount' times, this means that we can have a
		// window with 'maxOnesCount' 1s and the remaining are 0s which should replace
		// with 1s. Now, if the remaining 0s are more than 'k', it is the time to shrink
		// the window as we are not allowed to replace more than 'k' Os.
		if windowEnd-windowStart+1-maxOnesCount > k {
			if arr[windowStart] == 1 {
				maxOnesCount--
			}
			windowStart++
		}

		maxLength = max(maxLength, windowEnd-windowStart+1)
	}

	return maxLength
}
