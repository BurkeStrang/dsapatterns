// Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
// find the biggest island in it. Write a function to return the area of the
// biggest island. An island is a connected set of 1s (land) and is surrounded
// by either an edge or 0s (water). Each cell is considered connected to other
// cells horizontally or vertically (not diagonally).

import { inBounds } from "./shared.ts";

export function getIslandArea(
  matrix: number[][],
  x: number,
  y: number,
): number {
  if (!inBounds(matrix, x, y)) {
    return 0; // return, if it is not a valid cell
  }
  if (matrix[x][y] === 0) {
    return 0; // return, if it is a water cell
  }

  // mark the cell visited by making it a water cell
  matrix[x][y] = 0;

  let area = 1; // counting the current cell
  // recursively visit all neighboring cells (horizontally & vertically)
  area += getIslandArea(matrix, x + 1, y); // lower cell
  area += getIslandArea(matrix, x - 1, y); // upper cell
  area += getIslandArea(matrix, x, y + 1); // right cell
  area += getIslandArea(matrix, x, y - 1); // left cell
  return area;
}

export function maxAreaOfIsland(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length;
  let biggestIslandArea = 0;
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // only if the cell is a land
      if (matrix[i][j] === 1) {
        // we have found an island
        const area = getIslandArea(matrix, i, j);
        biggestIslandArea = Math.max(biggestIslandArea, area);
      }
    }
  }
  return biggestIslandArea;
}
