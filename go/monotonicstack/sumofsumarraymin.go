package monotonicstack

// Given an array of integers arr, return the sum of the minimum values from all possible contiguous subarrays within arr.
// Since the result can be very large, return the final sum modulo (109 + 7).
//
// Example 1:
// Input: arr = [3, 1, 2, 4, 5]
// Expected Output: 30
// Explanation:
// The subarrays are: [3], [1], [2], [4], [5], [3,1], [1,2], [2,4], [4,5], [3,1,2], [1,2,4], [2,4,5], [3,1,2,4], [1, 2, 4, 5], [3, 1, 2, 4, 5].
// The minimum values of these subarrays are: 3, 1, 2, 4, 5, 1, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Summing these minimums: 3 + 1 + 2 + 4 + 5 + 1 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1 + 1 = 30.
//
// Example 2:
// Input: arr = [2, 6, 5, 4]
// Expected Output: 36
// Explanation:
// The subarrays are: [2], [6], [5], [4], [2,6], [6,5], [5,4], [2,6,5], [6,5,4], [2,6,5,4].
// The minimum values of these subarrays are: 2, 6, 5, 4, 2, 5, 4, 2, 4, 2.
// Summing these minimums: 2 + 6 + 5 + 4 + 2 + 5 + 4 + 2 + 4 + 2 = 36.
//
// Example 3:
// Input: arr = [7, 3, 8]
// Expected Output: 35
// Explanation:
// The subarrays are: [7], [3], [8], [7,3], [3,8], [7,3,8].
// The minimum values of these subarrays are: 7, 3, 8, 3, 3, 3.
// Summing these minimums: 7 + 3 + 8 + 3 + 3 + 3 = 27.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

func sumSubarrayMins(arr []int) int {
	MOD := 1_000_000_007
	n := len(arr)
	result := 0 // Final sum of subarray minimums
	stack := []int{}

	// Iterate through the array plus one extra iteration for a sentinel.
	for currentIndex := 0; currentIndex <= n; currentIndex++ {
		// If we reached the end, use 0 as a sentinel value; otherwise, use the current element.
		// It helps to process all remaining elements in the stack.
		currentElement := 0
		if currentIndex < n {
			currentElement = arr[currentIndex]
		}

		// Process elements in the stack while the current element is smaller than the element at the top.
		// Here, we maintain monotonic increasing stack.
		for len(stack) > 0 && arr[stack[len(stack)-1]] > currentElement {
			// Pop the index whose corresponding element is greater than currentElement.
			minIndex := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			// Determine the previous index from the stack; if the stack is empty, use -1.
			previousIndex := -1
			if len(stack) > 0 {
				previousIndex = stack[len(stack)-1]
			}

			// Calculate the number of subarrays where arr[minIndex] is the minimum:
			// (minIndex - previousIndex) gives the count of subarrays ending at minIndex,
			// and (currentIndex - minIndex) gives the count of subarrays starting at minIndex
			// that can extend until currentIndex.
			countSubarrays := (minIndex - previousIndex) * (currentIndex - minIndex)

			// Add the contribution of arr[minIndex] for these subarrays to the result.
			result = (result + (arr[minIndex]*countSubarrays)%MOD) % MOD
		}

		// Push the current index onto the stack for further processing.
		stack = append(stack, currentIndex)
	}

	return result % MOD
}
