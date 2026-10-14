// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
//
// A closed island is an island that is totally surrounded by 0s (i.e., water).
// This means all horizontally and vertically connected cells of a closed island
// are water.
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
// Output: 1 Explanation: The given matrix has two islands, but only the
// highlighted island is a closed island.
// The other island is touching the boundary that's why is is not considered a
// closed island.
//
// Example 2
// Input: matrix = [1,1,1,1,1,1,1,0]
// 								 [1,0,0,0,0,1,1,0]
// 								 [0,0,1,0,1,0,1,0]
// 								 [0,0,0,0,0,0,1,0]
// Output: 2
// Explanation: The given matrix has two islands and both of them are closed
// islands.
//
// Constraints:
//
// 0 <= grid[i][j] <=1

import { inBounds } from "./shared.ts";

// isClosedIslandDfs checks if the island is closed using DFS
export function isClosedIslandDfs(
  matrix: number[][],
  visited: boolean[][],
  x: number,
  y: number,
): boolean {
  if (!inBounds(matrix, x, y)) {
    return false; // returning false since the island is touching an edge
  }
  if (matrix[x][y] === 0 || visited[x][y]) {
    return true; // returning true as the island is surrounded by water
  }

  visited[x][y] = true; // mark the cell visited

  // recursively visit all neighboring cells (horizontally & vertically).
  // visit every neighbor even after one reaches an edge: stopping early
  // leaves the rest of the island unvisited, and it is counted again later
  const down = isClosedIslandDfs(matrix, visited, x + 1, y);
  const up = isClosedIslandDfs(matrix, visited, x - 1, y);
  const right = isClosedIslandDfs(matrix, visited, x, y + 1);
  const left = isClosedIslandDfs(matrix, visited, x, y - 1);
  return down && up && right && left;
}

export function countClosedIslands(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length;
  let closedIslands = 0;
  const visited = Array.from({ length: rows }, () =>
    new Array<boolean>(cols).fill(false),
  );
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // only if the cell is a land and not visited
      if (
        matrix[i][j] === 1 &&
        !visited[i][j] &&
        isClosedIslandDfs(matrix, visited, i, j)
      ) {
        closedIslands++;
      }
    }
  }
  return closedIslands;
}
