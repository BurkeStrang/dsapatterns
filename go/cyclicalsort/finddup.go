package cyclicalsort

// We are given an unsorted array containing n+1 numbers taken from the range 1 to n.
// The array has only one duplicate but it can be repeated multiple times.
// Find that duplicate number without using any extra space.
// You are, however, allowed to modify the input array.
//
// Example 1:
// Input: [1, 4, 4, 3, 2]
// Output: 4
//
// Example 2:
// Input: [2, 1, 3, 3, 5, 4]
// Output: 3
//
// Example 3:
// Input: [2, 4, 1, 4, 4]
// Output: 4
// Constraints:
//
// nums.length == n + 1
// 1 <= n <=
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

func findDup(arr []int) int {
	slow, fast := 0, 0
	// Find the intersection point of the two runners.
	for {
		slow = arr[slow]
		fast = arr[arr[fast]]
		if slow == fast {
			break
		}
	}
	// Find the cycle length
	current := arr[slow]
	cycleLength := 1
	for arr[current] != arr[slow] {
		current = arr[current]
		cycleLength++
	}
	return findStart(arr, cycleLength)
}

func findStart(arr []int, cycleLength int) int {
	pointer1, pointer2 := arr[0], arr[0]
	// Move pointer2 ahead 'cycleLength' steps
	for range cycleLength {
		pointer2 = arr[pointer2]
	}
	// Increment both pointers until they meet at the start of the cycle
	for pointer1 != pointer2 {
		pointer1 = arr[pointer1]
		pointer2 = arr[pointer2]
	}
	return pointer1
}
