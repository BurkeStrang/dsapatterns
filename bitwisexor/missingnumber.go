package bitwisexor
// Given an array of n-1 integers in the range from 1 to n,
// find the one number that is missing from the array.
// Solve the problem in O(n) time and without using any extra space. You can
// modify the input array. Be aware of large n, which can cause integer overflow
// if you are calculating the sum of numbers from 1 to n.
//
// Example 1:
// Input: [1, 2, 3, 5]
// Output: 4

func findMissingNumber(arr []int) int {
	n := len(arr) + 1
	x1 := 1
	for i := 2; i <= n; i++ {
		x1 ^= i
	}

	x2 := arr[0]
	for i := 1; i < len(arr); i++ {
		x2 ^= arr[i]
	}

	return x1 ^ x2
}
