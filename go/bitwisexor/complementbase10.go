package bitwisexor

import "math"

// Every non-negative integer N has a binary representation.
// For example:
//   8  -> 1000
//   7  -> 0111
//
// The complement of a binary representation is obtained by flipping
// every bit: 1 becomes 0 and 0 becomes 1.
//
// Example 1:
// Input: 8
// Output: 7
// Explanation:
// 8  = 1000
// complement = 0111 = 7
//
// Example 2:
// Input: 10
// Output: 5
// Explanation:
// 10 = 1010
// complement = 0101 = 5

func bitwiseComplement(num int) int {

	// Count how many bits are needed to represent 'num'
	bitCount := 0
	n := num

	// Example for num = 10 (binary 1010):
	// iteration 1: n = 1010 → bitCount = 1
	// iteration 2: n = 101  → bitCount = 2
	// iteration 3: n = 10   → bitCount = 3
	// iteration 4: n = 1    → bitCount = 4
	// iteration 5: n = 0    → loop exits
	for n > 0 {
		bitCount++
		n >>= 1
	}

	// Create a number where all bits up to the most significant bit
	// of 'num' are set to 1.
	//
	// A power of two minus one produces a sequence of 1s in binary:
	//   2^1 - 1 = 1  -> 1
	//   2^2 - 1 = 3  -> 11
	//   2^3 - 1 = 7  -> 111
	//   2^4 - 1 = 15 -> 1111
	//
	// Example with num = 10:
	// bitCount = 4
	// 2^4 = 16
	// allBitsSet = 16 - 1 = 15 -> binary 1111
	allBitsSet := int(math.Pow(2, float64(bitCount))) - 1

	// XOR flips the bits wherever the mask has a 1
	//
	// Example:
	//   num       = 1010 (10)
	//   allBitsSet= 1111 (15)
	// -----------------------
	//   result    = 0101 (5)
	return num ^ allBitsSet
}
