package islandtraversal

func maxAreaOfIsland(matrix [][]int) int {
	rows := len(matrix)
	cols := len(matrix[0])
	biggestIslandArea := 0

	for i := range rows {
		for j := range cols {
			if matrix[i][j] == 1 { // only if the cell is a land
				// we have found an island
				biggestIslandArea = max(biggestIslandArea, getIslandArea(matrix, i, j))
			}
		}
	}
	return biggestIslandArea
}

func getIslandArea(matrix [][]int, x, y int) int {
	if x < 0 || x >= len(matrix) || y < 0 || y >= len(matrix[0]) {
		return 0 // return, if it is not a valid cell
	}
	if matrix[x][y] == 0 {
		return 0 // return, if it is a water cell
	}

	matrix[x][y] = 0 // mark the cell visited by making it a water cell

	area := 1 // counting the current cell
	// recursively visit all neighboring cells (horizontally & vertically)
	area += getIslandArea(matrix, x+1, y) // lower cell
	area += getIslandArea(matrix, x-1, y) // upper cell
	area += getIslandArea(matrix, x, y+1) // right cell
	area += getIslandArea(matrix, x, y-1) // left cell

	return area
}
