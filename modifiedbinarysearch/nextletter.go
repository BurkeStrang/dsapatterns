package modifiedbinarysearch

// Example 1:
// Input: ['a', 'c', 'f', 'h'], key = 'f'
// Output: 'h'

func searchNextLetter(letters []string, key string) string {

	n := len(letters)
	left := 0
	right := n - 1

	for left <= right {
		mid := left + (right-left)/2
		if key < letters[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	// Since the loop is running until 'left <= right', so at the right of the while loop,
	// 'left == right+1'
	return letters[left%n]
}
