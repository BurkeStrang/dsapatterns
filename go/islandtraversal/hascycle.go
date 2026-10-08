package islandtraversal

// You are given a 2D matrix containing different characters,
// you need to find if there exists any cycle consisting of the same character in the matrix.
// A cycle is a path in the matrix that starts and ends at the same cell and has four or more cells.
// From a given cell,
// you can move to one of the cells adjacent to it - in one of the four directions
// (up, down, left, or right), if it has the same character value of the current cell.
// Write a function to find if the matrix has a cycle.

func hasCycle(matrix [][]rune) bool {
	rows := len(matrix)
	cols := len(matrix[0])
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}

	for i := range rows {
		for j := range cols {
			if dfsCycle(matrix, visited, i, j, i, j, matrix[i][j]) {
				return true
			}
		}
	}
	return false
}

func dfsCycle(matrix [][]rune, visited [][]bool, x, y, prevx, prevy int, orgchar rune) bool {
	if x < 0 || x >= len(matrix) || y < 0 || y >= len(matrix[0]) || matrix[x][y] != orgchar {
		return false
	}
	if visited[x][y] {
		return true
	}

	visited[x][y] = true

	if x+1 != prevx && dfsCycle(matrix, visited, x+1, y, x, y, orgchar) {
		return true
	}
	if x-1 != prevx && dfsCycle(matrix, visited, x-1, y, x, y, orgchar) {
		return true
	}
	if y+1 != prevy && dfsCycle(matrix, visited, x, y+1, x, y, orgchar) {
		return true
	}
	if y-1 != prevy && dfsCycle(matrix, visited, x, y-1, x, y, orgchar) {
		return true
	}
	return false
}
