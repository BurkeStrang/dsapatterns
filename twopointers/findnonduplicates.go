package twopointers

func moveElements(arr []int) int {
	// Initialize the pointer to the next non-duplicate element as 1.
	nextNonDuplicate := 1

	// Iterate through the input slice.
	for i := 1; i < len(arr); i++ {
		// Check if the element at the nextNonDuplicate-1 position is not equal to the current element.
		if arr[nextNonDuplicate-1] != arr[i] {
			// If they are not equal, update the element at the nextNonDuplicate position with the current element.
			arr[nextNonDuplicate] = arr[i]

			// Increment the nextNonDuplicate pointer.
			nextNonDuplicate++
		}
	}

	// Return the length of the modified slice without duplicates.
	return nextNonDuplicate
}
