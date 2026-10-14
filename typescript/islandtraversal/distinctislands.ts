// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

import { inBounds } from "./shared.ts";

export function traverseIslandDfs(
  matrix: number[][],
  visited: boolean[][],
  x: number,
  y: number,
  path: string[],
  direction: string,
): void {
  if (!inBounds(matrix, x, y)) {
    return; // return if it is not a valid cell
  }
  if (matrix[x][y] === 0 || visited[x][y]) {
    return; // return if it is a water cell or is visited
  }

  visited[x][y] = true; // mark the cell visited
  path.push(direction);

  // recursively visit all neighboring cells (horizontally & vertically)
  traverseIslandDfs(matrix, visited, x + 1, y, path, "D"); // down
  traverseIslandDfs(matrix, visited, x - 1, y, path, "U"); // up
  traverseIslandDfs(matrix, visited, x, y + 1, path, "R"); // right
  traverseIslandDfs(matrix, visited, x, y - 1, path, "L"); // left

  path.push("B"); // back
}

export function findDistinctIslandsDfs(matrix: number[][]): number {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const visited = Array.from({ length: rows }, () =>
    new Array<boolean>(cols).fill(false),
  );
  const islandsSet = new Set<string>();
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      // only if the cell is a land and not visited
      if (matrix[i][j] === 1 && !visited[i][j]) {
        const islandTraversal: string[] = [];
        // "O" marks the origin of the island
        traverseIslandDfs(matrix, visited, i, j, islandTraversal, "O");
        islandsSet.add(islandTraversal.join(""));
      }
    }
  }
  return islandsSet.size;
}
