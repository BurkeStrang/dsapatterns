package unionfind

import "sort"

// You are given a 2D array heights[][] of size n x m,
// where heights[n][m] represents the height of the cell (n, m).
// Find a path from the top-left corner to the bottom-right c
// orner that minimizes the effort required to travel between consecutive points,
// where effort is defined as the absolute difference in height between two points.
// In a single step, you can either move up, down, left or right.
// Return the minimum effort required for any path from the first point to the last.
//
// Example 1:
// Input: heights =
//  [[1,2,3],[3,8,4],[5,3,5]]
// Expected Output: 1
// Justification: The path with the minimum effort is along the edges of the grid (right, right, down, down)
// which requires an effort of 1 between each pair of points.
//
// Example 2:
// Input: heights =
// [[1,2,2],[3,3,3],[5,3,1]]
// Expected Output: 2
// Justification: The path that minimizes the maximum effort goes through (1,2,2,3,1),
// which has a maximum effort of 2 (from 3 to 1).
//
// Example 3:
// Input: heights =
// [[1,1,1],[1,1,1],[1,1,1]]
// Expected Output: 0
// Justification: The path that minimizes the maximum effort goes through (1,1,1,1,1),
// which has a maximum effort of 0.
//
// Constraints:
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106

// edge joins two neighboring cells; difference is the effort to step
// between them.
type edge struct {
	x          int
	y          int
	difference int
}

func minimumEffortPath(heights [][]int) int {
	row := len(heights)
	col := len(heights[0])

	uf := newUnionFind(row * col)

	// every cell is numbered i*col + j, and has an edge to the cell above it
	// and the cell to its left
	edges := make([]edge, 0)

	for i := range row {
		for j := range col {
			if i > 0 {
				edges = append(edges, edge{
					x:          i*col + j,
					y:          (i-1)*col + j,
					difference: abs(heights[i][j] - heights[i-1][j]),
				})
			}

			if j > 0 {
				edges = append(edges, edge{
					x:          i*col + j,
					y:          i*col + j - 1,
					difference: abs(heights[i][j] - heights[i][j-1]),
				})
			}
		}
	}

	sort.Slice(edges, func(a, b int) bool {
		return edges[a].difference < edges[b].difference
	})

	// add the edges from the smallest effort up; the edge that first joins
	// the top-left and bottom-right cells is the largest step on the best path
	for _, e := range edges {
		uf.union(e.x, e.y)

		if uf.connected(0, row*col-1) {
			return e.difference
		}
	}

	return 0
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
