// You are given a 2D matrix containing different characters,
// you need to find if there exists any cycle consisting of the same character
// in the matrix.
// A cycle is a path in the matrix that starts and ends at the same cell and has
// four or more cells.
// From a given cell,
// you can move to one of the cells adjacent to it - in one of the four
// directions
// (up, down, left, or right), if it has the same character value of the current
// cell.
// Write a function to find if the matrix has a cycle.

import { inBounds } from "./shared.ts";

export function dfsCycle(
  matrix: string[][],
  visited: boolean[][],
  x: number,
  y: number,
  prevX: number,
  prevY: number,
  orgChar: string,
): boolean {
  if (!inBounds(matrix, x, y) || matrix[x][y] !== orgChar) {
    return false;
  }
  if (visited[x][y]) {
    return true;
  }
  visited[x][y] = true;

  // visit every neighbor except the cell we just came from
  return (
    (x + 1 !== prevX && dfsCycle(matrix, visited, x + 1, y, x, y, orgChar)) ||
    (x - 1 !== prevX && dfsCycle(matrix, visited, x - 1, y, x, y, orgChar)) ||
    (y + 1 !== prevY && dfsCycle(matrix, visited, x, y + 1, x, y, orgChar)) ||
    (y - 1 !== prevY && dfsCycle(matrix, visited, x, y - 1, x, y, orgChar))
  );
}

export function hasCycle(matrix: string[][]): boolean {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const visited = Array.from({ length: rows }, () =>
    new Array<boolean>(cols).fill(false),
  );
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (dfsCycle(matrix, visited, i, j, i, j, matrix[i][j])) {
        return true;
      }
    }
  }
  return false;
}
