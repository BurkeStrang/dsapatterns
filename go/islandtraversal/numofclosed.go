package islandtraversal

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically (not diagonally).
//
// A closed island is an island that is totally surrounded by 0s (i.e., water).
// This means all horizontally and vertically connected cells of a closed island are water.
// This also means that, by definition, a closed island can't touch an edge
// (as then the edge cells are not connected to any water cell).
//
// Write a function to find the number of closed islands in the given matrix.
//
// Example 1
// Input: matrix = [1,1,1,1,1,1,1]
// 								 [0,0,1,0,0,0,1]
// 								 [0,0,1,0,0,1,0]
// 								 [0,0,1,0,0,1,0]
// 								 [0,0,0,0,0,0,0]
// Output: 1 Explanation: The given matrix has two islands, but only the highlighted island is a closed island.
// The other island is touching the boundary that's why is is not considered a closed island.
//
// Example 2
// Input: matrix = [1,1,1,1,1,1,1,0]
// 								 [1,0,0,0,0,1,1,0]
// 								 [0,0,1,0,1,0,1,0]
// 								 [0,0,0,0,0,0,1,0]
// Output: 2
// Explanation: The given matrix has two islands and both of them are closed islands.
//
// Constraints:
//
// 0 <= grid[i][j] <=1

func countClosedIslands(matrix [][]int) int {
	rows := len(matrix)
	cols := len(matrix[0])
	countClosedIslands := 0
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}

	for i := range rows {
		for j := range cols {
			if matrix[i][j] == 1 && !visited[i][j] { // only if the cell is a land and not visited
				if isClosedIslandDFS(matrix, visited, i, j) {
					countClosedIslands++
				}
			}
		}
	}
	return countClosedIslands
}

// isClosedIslandDFS checks if the island is closed using DFS
func isClosedIslandDFS(matrix [][]int, visited [][]bool, x, y int) bool {
	if x < 0 || x >= len(matrix) || y < 0 || y >= len(matrix[0]) {
		return false // returning false since the island is touching an edge
	}
	if matrix[x][y] == 0 || visited[x][y] {
		return true // returning true as the island is surrounded by water
	}

	visited[x][y] = true // mark the cell visited

	isClosed := true
	// recursively visit all neighboring cells (horizontally & vertically)
	isClosed = isClosed && isClosedIslandDFS(matrix, visited, x+1, y) // lower cell
	isClosed = isClosed && isClosedIslandDFS(matrix, visited, x-1, y) // upper cell
	isClosed = isClosed && isClosedIslandDFS(matrix, visited, x, y+1) // right cell
	isClosed = isClosed && isClosedIslandDFS(matrix, visited, x, y-1) // left cell

	return isClosed
}
