package bitwisexor

// Given a square binary matrix representing an image,
// we want to flip the image horizontally, then invert it.
// To flip an image horizontally means that each row of the image is reversed.
// For example, flipping [0, 1, 1] horizontally results in [1, 1, 0].
// To invert an image means that each 0 is replaced by 1,
// and each 1 is replaced by 0. For example, inverting [1, 1, 0] results in [0, 0, 1].
//
// Example 1:
// Input: [
//   [1,0,1],
//   [1,1,1],
//   [0,1,1]
// ]
// Output: [
//   [0,1,0],
//   [0,0,0],
//   [0,0,1]
// ]
// Explanation: First reverse each row: [[1,0,1],[1,1,1],[1,1,0]]. Then, invert the image: [[0,1,0],[0,0,0],[0,0,1]]
//
// Example 2:
// Input: [
//   [1,1,0,0],
//   [1,0,0,1],
//   [0,1,1,1],
//   [1,0,1,0]
// ]
// Output: [
//   [1,1,0,0],
//   [0,1,1,0],
//   [0,0,0,1],
//   [1,0,1,0]
// ]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]. Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

func flipAndInvertImage(arr [][]int) [][]int {
	C := len(arr[0]) // Get the number of columns in the matrix
	for _, row := range arr {
		for i := 0; i < (C+1)/2; i++ {
			// Swap and invert elements symmetrically from the beginning and end of the row
			tmp := row[i] ^ 1
			row[i] = row[C-1-i] ^ 1
			row[C-1-i] = tmp
		}
	}
	return arr
}
