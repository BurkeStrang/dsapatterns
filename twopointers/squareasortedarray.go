package twopointers

// Problem Statement
// Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
//
// Example 1:
//
// Input: [-2, -1, 0, 2, 3]
// Output: [0, 1, 4, 4, 9]
// Example 2:
//
// Input: [-3, -1, 0, 1, 2]
// Output: [0, 1, 1, 4, 9]
// Constraints:
//
// 1 <= arr.length <= 104
// -104 <= arr[i] <= 104
// arr is sorted in non-decreasing order.

func makeSquares(arr []int) []int {
	n := len(arr)
	squares := make([]int, n)
	highestSquareIdx := n - 1 // Initialize an index for the highest value in the output slice.
	left, right := 0, n-1     // Initialize two pointers, left and right, for the input array.

	// Traverse the input array from both ends towards the center.
	for left <= right {
		leftSquare := arr[left] * arr[left]    // Calculate the square of the element at the left pointer.
		rightSquare := arr[right] * arr[right] // Calculate the square of the element at the right pointer.

		// Compare the squared values and store the larger one in the output slice.
		if leftSquare > rightSquare {
			squares[highestSquareIdx] = leftSquare // Store the left squared value in the output slice.
			highestSquareIdx--                     // Move the output index one position to the left.
			left++                                 // Move the left pointer to the right.
		} else {
			squares[highestSquareIdx] = rightSquare // Store the right squared value in the output slice.
			highestSquareIdx--                      // Move the output index one position to the left.
			right--                                 // Move the right pointer to the left.
		}
	}
	return squares
}
