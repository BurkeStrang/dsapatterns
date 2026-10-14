// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// There are no lakes on the island, so the water inside the island is not
// connected to the water around it.
// A cell is a square with a side length of 1.
// The given matrix has only one island, write a function to find the perimeter
// of that island.

import { inBounds } from "./shared.ts";

export function dfs(
  matrix: number[][],
  visited: boolean[][],
  x: number,
  y: number,
): number {
  if (!inBounds(matrix, x, y)) {
    // returning 1, since this a boundary cell initiated this DFS call
    return 1;
  }
  if (matrix[x][y] === 0) {
    // returning 1, because of the shared side b/w a water and a land cell
    return 1;
  }
  if (visited[x][y]) {
    return 0; // we have already taken care of this cell
  }

  visited[x][y] = true; // mark the cell visited
  let edgeCount = 0;
  // recursively visit all neighboring cells (horizontally & vertically)
  edgeCount += dfs(matrix, visited, x + 1, y); // lower cell
  edgeCount += dfs(matrix, visited, x - 1, y); // upper cell
  edgeCount += dfs(matrix, visited, x, y + 1); // right cell
  edgeCount += dfs(matrix, visited, x, y - 1); // left cell
  return edgeCount;
}

export function findIslandPerimeter(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const visited = Array.from({ length: rows }, () =>
    new Array<boolean>(cols).fill(false),
  );
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // only if the cell is a land and not visited
      if (matrix[i][j] === 1 && !visited[i][j]) {
        return dfs(matrix, visited, i, j);
      }
    }
  }
  return 0;
}
