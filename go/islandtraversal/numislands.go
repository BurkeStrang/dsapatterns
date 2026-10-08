package islandtraversal

// Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
// count the number of islands in it.
//
// An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically (not diagonally).
//
// Example 1
// Input: matrix = [1,1,1,0,0],
// 								 [0,1,0,0,1],
// 								 [0,0,1,1,0],
// 								 [0,0,1,0,0],
// 								 [0,0,1,0,0]
// Output: 3
//
// Example 2
// Input: matrix = [1,1,0,0,0],
// 								 [0,1,0,0,0],
// 								 [0,1,0,0,0],
// 								 [0,1,0,0,0],
// Output: 1
//
// Image
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

func countIslands(matrix [][]int) int {
	rows := len(matrix)
	cols := len(matrix[0])
	totalIslands := 0

	for i := range rows {
		for j := range cols {
			if matrix[i][j] == 1 { // only if the cell is a land
				// we have found an island
				totalIslands++
				visitIslandDFS(matrix, i, j)
			}
		}
	}
	return totalIslands
}

// visitIslandDFS performs a depth-first search to visit all parts of an island
func visitIslandDFS(matrix [][]int, x int, y int) {
	if x < 0 || x >= len(matrix) || y < 0 || y >= len(matrix[0]) {
		return // return, if it is not a valid cell
	}
	if matrix[x][y] == 0 {
		return // return, if it is a water cell
	}

	matrix[x][y] = 0 // mark the cell visited by making it a water cell

	// recursively visit all neighboring cells (horizontally & vertically)
	visitIslandDFS(matrix, x+1, y) // lower cell
	visitIslandDFS(matrix, x-1, y) // upper cell
	visitIslandDFS(matrix, x, y+1) // right cell
	visitIslandDFS(matrix, x, y-1) // left cell
}
