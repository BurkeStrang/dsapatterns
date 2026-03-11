package bitwisexor

// Given an array of n-1 integers in the range from 1 to n,
// find the one number that is missing from the array.
// Solve the problem in O(n) time and without using any extra space. You can
// modify the input array. Be aware of large n, which can cause integer overflow
// if you are calculating the sum of numbers from 1 to n.
//
// Example 1:
// Input: [1,5,2,6,4]
// Output: 3

func findMissingNumber(arr []int) int {

	// The array contains n-1 numbers from the range 1..n
	// so the actual range size is length + 1
	//
	// Example:
	// arr = [1,5,2,6,4]
	// len(arr) = 5
	// numbers should be 1..6
	n := len(arr) + 1

	// x1 will hold XOR of all numbers from 1..n
	x1 := 1

	// XOR all numbers from 1..n
	//
	// Example progression:
	// start x1 = 1
	//
	// i=2 → x1 = 1 ^ 2 = 3, binary: 0001 ^ 0010 = 0011
	// i=3 → x1 = 3 ^ 3 = 0, binary: 0011 ^ 0011 = 0000
	// i=4 → x1 = 0 ^ 4 = 4, binary: 0000 ^ 0100 = 0100
	// i=5 → x1 = 4 ^ 5 = 1, binary: 0100 ^ 0101 = 0001
	// i=6 → x1 = 1 ^ 6 = 7, binary: 0001 ^ 0110 = 0111
	//
	// final x1 = XOR(1,2,3,4,5,6) = 7
	for i := 2; i <= n; i++ {
		x1 ^= i
	}

	// x2 will hold XOR of all elements in the array
	x2 := arr[0]

	// XOR all array values
	//
	// Example arr = [1,5,2,6,4]
	//
	// start x2 = 1
	//
	// i=1 → x2 = 1 ^ 5 = 4, binary: 0001 ^ 0101 = 0100
	// i=2 → x2 = 4 ^ 2 = 6, binary: 0100 ^ 0010 = 0110
	// i=3 → x2 = 6 ^ 6 = 0, binary: 0110 ^ 0110 = 0000
	// i=4 → x2 = 0 ^ 4 = 4, binary: 0000 ^ 0100 = 0100
	//
	// final x2 = XOR(1,5,2,6,4) = 4
	for i := 1; i < len(arr); i++ {
		x2 ^= arr[i]
	}

	// Now XOR both results
	//
	// x1 = XOR(1..6) = 7
	// x2 = XOR(array) = 4
	//
	// result = 7 ^ 4 = 3
	//
	// Why this works:
	//
	// (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6)
	// ^
	// (1 ^ 5 ^ 2 ^ 6 ^ 4)
	//
	// matching numbers cancel out:
	//
	// 1^1 = 0
	// 2^2 = 0
	// 4^4 = 0
	// 5^5 = 0
	// 6^6 = 0
	//
	// leaving only:
	// 3
	// x1 binary: 0111
	// x2 binary: 0100
	// last step: 0111 ^ 0100 = 0011
	return x1 ^ x2
}
