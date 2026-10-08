package modifiedbinarysearch

func descorascsearch(arr []int, key int) int {
	left, right := 0, len(arr)-1
	isAsc := arr[left] < arr[right]
	for left <= right {
		// calculate the middle of the current range
		mid := left + (right-left)/2

		if key == arr[mid] {
			return mid
		}

		if isAsc { // ascending order
			if key < arr[mid] {
				right = mid - 1 // the 'key' can be in the first half
			} else { // key > arr[mid]
				left = mid + 1 // the 'key' can be in the second half
			}
		} else { // descending order
			if key > arr[mid] {
				right = mid - 1 // the 'key' can be in the first half
			} else { // key < arr[mid]
				left = mid + 1 // the 'key' can be in the second half
			}
		}
	}
	return -1 // element not found
}
