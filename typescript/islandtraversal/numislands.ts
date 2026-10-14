// Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
// count the number of islands in it.
//
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
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

import { inBounds } from "./shared.ts";

// visitIslandDfs performs a depth-first search to visit all parts of an
// island
export function visitIslandDfs(matrix: number[][], x: number, y: number): void {
  if (!inBounds(matrix, x, y)) {
    return; // return, if it is not a valid cell
  }
  if (matrix[x][y] === 0) {
    return; // return, if it is a water cell
  }

  // mark the cell visited by making it a water cell
  matrix[x][y] = 0;

  // recursively visit all neighboring cells (horizontally & vertically)
  visitIslandDfs(matrix, x + 1, y); // lower cell
  visitIslandDfs(matrix, x - 1, y); // upper cell
  visitIslandDfs(matrix, x, y + 1); // right cell
  visitIslandDfs(matrix, x, y - 1); // left cell
}

export function countIslands(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length;
  let totalIslands = 0;
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // only if the cell is a land
      if (matrix[i][j] === 1) {
        // we have found an island
        totalIslands++;
        visitIslandDfs(matrix, i, j);
      }
    }
  }
  return totalIslands;
}
