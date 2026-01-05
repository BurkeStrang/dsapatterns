package islandtraversal

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

func findDistinctIslandsDFS(matrix [][]int) int {
	rows := len(matrix)
	cols := len(matrix[0])
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}
	islandsSet := make(map[string]bool)

	for i := range rows {
		for j := range cols {
			if matrix[i][j] == 1 && !visited[i][j] { // only if the cell is a land and not visited
				var islandTraversal string
				traverseIslandDFS(matrix, visited, i, j, &islandTraversal, "O") // origin
				islandsSet[islandTraversal] = true
				println("----") // Debug print
				println("Island Traversal:", islandTraversal) // Debug print
				println("Total Distinct Islands So Far:", len(islandsSet)) // Debug print
				println("----") // Debug print
			}
		}
	}
	return len(islandsSet)
}

func traverseIslandDFS(matrix [][]int, visited [][]bool, x, y int, islandTraversal *string, direction string) {
	if x < 0 || x >= len(matrix) || y < 0 || y >= len(matrix[0]) {
		return // return if it is not a valid cell
	}
	if matrix[x][y] == 0 || visited[x][y] {
		return // return if it is a water cell or is visited
	}

	visited[x][y] = true // mark the cell visited

	*islandTraversal += direction
	// recursively visit all neighboring cells (horizontally & vertically)
	traverseIslandDFS(matrix, visited, x+1, y, islandTraversal, "D") // down
	traverseIslandDFS(matrix, visited, x-1, y, islandTraversal, "U") // up
	traverseIslandDFS(matrix, visited, x, y+1, islandTraversal, "R") // right
	traverseIslandDFS(matrix, visited, x, y-1, islandTraversal, "L") // left

	*islandTraversal += "B" // back
}
