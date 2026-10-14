// Helpers shared by the island traversal problems.

// inBounds reports whether (x, y) is a cell of the matrix. The traversals
// step one cell past every edge, so x and y may be -1 or one past the end.
export function inBounds(matrix: unknown[][], x: number, y: number): boolean {
  return x >= 0 && x < matrix.length && y >= 0 && y < matrix[0].length;
}
