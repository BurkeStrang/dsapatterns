package slidingwindow

// Given an array, find the average of each subarray of ‘K’ contiguous elements in it.

func findAverages(k int, arr []int) []float64 {
	result := make([]float64, len(arr)-k+1)
	windowSum := 0
	windowStart := 0
	for windowEnd := range arr {
		windowSum += arr[windowEnd] // add the next element
		// slide the window, we don't need to slide if we've not hit the required
		// window size of 'k'
		if windowEnd >= k-1 {
			result[windowStart] = float64(windowSum) / float64(k) // calculate the average
			windowSum -= arr[windowStart]                         // subtract the element going out
			windowStart++                                         // slide the window ahead
		}
	}
	return result
}
