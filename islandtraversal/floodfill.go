package islandtraversal

// Any image can be represented by a 2D integer array (i.e., a matrix) where each cell represents the pixel value of the image.
// Flood fill algorithm takes a starting cell (i.e., a pixel) and a color. The given color is applied to all horizontally and vertically connected cells with the same color as that of the starting cell. Recursively, the algorithm fills cells with the new color until it encounters a cell with a different color than the starting cell.
// Given a matrix, a starting cell, and a color, flood fill the matrix.
//
// Example 1:
// Input: matrix = 	[0,0,0,1,1]
//									[1,0,0,1,1]
//									[1,0,0,1,1]
// starting cell = (1, 3)
// new color = 2
// Output: new matrix = [0,0,0,2,2]
// 											[1,0,0,2,2]
// 											[1,0,0,2,2]
//
// Example 2:
// Input: matrix = 	[0,0,0,1,1]
//									[1,0,0,1,1]
//									[1,0,0,1,1]
//									[1,0,1,1,1]
// starting cell = (3, 2)
// new color = 5
// Output: new matrix = [0,0,0,5,5]
// 											[1,0,0,5,5]
// 											[1,0,0,5,5]
//											[1,0,5,5,5]
//
// Constraints:
// m == matrix.length
// n == - m == matrix[i].length
// 1 <= m, n <= 50
// 0 <= - m == matrix[i][j], color < 216
// 0 <= x < m
// 0 <= y < n

func floodFill(matrix [][]int, x, y, newColor int) [][]int {
	if len(matrix) < x || len(matrix[0]) < y {
		return matrix
	}
	if matrix[x][y] == 1 {
		floodFillDFS(matrix, x, y, newColor)
	}
	return matrix
}

func floodFillDFS(matrix [][]int, x, y, newColor int) {
	m := len(matrix)
	n := len(matrix[0])
	matrix[x][y] = newColor
	moves := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for _, move := range moves {
		mx := x + move[0]
		my := y + move[1]
		matched := mx >= 0 && mx < m && my >= 0 && my < n && matrix[mx][my] == 1
		if matched {
			floodFillDFS(matrix, mx, my, newColor)
		}
	}
}
