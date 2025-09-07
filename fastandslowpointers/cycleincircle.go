package fastandslowpointers

// We are given an array containing positive and negative numbers. Suppose the array contains a number ‘M’ at a particular index.
// Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’ indices.
// You should assume that the array is circular which means two things:
//
// If, while moving forward, we reach the end of the array, we will jump to the first element to continue the movement.
// If, while moving backward, we reach the beginning of the array, we will jump to the last element to continue the movement.
// Write a method to determine if the array has a cycle.
// The cycle should have more than one element and should follow one direction which means the cycle should not contain both forward and backward movements.
//
// Example 1:
//
// Input: [1, 2, -1, 2, 2]
// Output: true
// Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0
// Example 2:
//
// Input: [2, 2, -1, 2]
// Output: true
// Explanation: The array has a cycle among indices: 1 -> 3 -> 1
// Example 3:
//
// Input: [2, 1, -1, -2]
// Output: false
// Explanation: The array does not have any cycle.
// Constraints:
//
// 1 <= nums.length <= 5000
// `-1000 <= nums[i] <= 1000
// nums[i] != 0

func loopExists(arr []int) bool {
	for i := range arr {
		isForward := arr[i] >= 0 // if we are moving forward or not
		slow, fast := i, i

		// if slow or fast becomes '-1' this means we can't find cycle for this number
		for {
			slow = findNextIndex(arr, isForward, slow) // move one step for slow pointer
			fast = findNextIndex(arr, isForward, fast) // move one step for fast pointer
			if fast != -1 {
				fast = findNextIndex(arr, isForward, fast) // move another step for fast ptr
			}
			if slow == -1 || fast == -1 || slow == fast {
				break
			}
		}

		if slow != -1 && slow == fast {
			return true
		}
	}

	return false
}

func findNextIndex(arr []int, isForward bool, currentIndex int) int {
	direction := arr[currentIndex] >= 0
	if isForward != direction {
		return -1 // change in direction, return -1
	}

	nextIndex := (currentIndex + arr[currentIndex]) % len(arr)
	if nextIndex < 0 {
		nextIndex += len(arr) // wrap around for negative numbers
	}

	// one element cycle, return -1
	if nextIndex == currentIndex {
		nextIndex = -1
	}
	return nextIndex
}
