package modifiedbinarysearch

func searchCeilingOfANumber(arr []int, key int) int {
	if key > arr[len(arr)-1] { // if the 'key' is bigger than the biggest element
		return -1
	}

	start, end := 0, len(arr)-1
	for start <= end {
		mid := start + (end-start)/2
		switch {
		case key < arr[mid]:
			end = mid - 1
		case key > arr[mid]:
			start = mid + 1
		default: // found the key
			return mid
		}
	}
	// since the loop is running until 'start <= end', so at the end of the while loop,
	// 'start == end+1' we are not able to find the element in the given array, so the
	// next big number will be arr[start]
	return start
}
