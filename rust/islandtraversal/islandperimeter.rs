use super::shared::in_bounds;

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

pub fn find_island_perimeter(matrix: &[Vec<i32>]) -> usize {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut visited = vec![vec![false; cols]; rows];

    for i in 0..rows {
        for j in 0..cols {
            // only if the cell is a land and not visited
            if matrix[i][j] == 1 && !visited[i][j] {
                return dfs(matrix, &mut visited, i as i32, j as i32);
            }
        }
    }
    0
}

fn dfs(
    matrix: &[Vec<i32>],
    visited: &mut [Vec<bool>],
    x: i32,
    y: i32,
) -> usize {
    if !in_bounds(matrix, x, y) {
        // returning 1, since this a boundary cell initiated this DFS call
        return 1;
    }
    let (row, col) = (x as usize, y as usize);
    if matrix[row][col] == 0 {
        // returning 1, because of the shared side b/w a water and a land cell
        return 1;
    }
    if visited[row][col] {
        return 0; // we have already taken care of this cell
    }

    visited[row][col] = true; // mark the cell visited

    let mut edge_count = 0;
    // recursively visit all neighboring cells (horizontally & vertically)
    edge_count += dfs(matrix, visited, x + 1, y); // lower cell
    edge_count += dfs(matrix, visited, x - 1, y); // upper cell
    edge_count += dfs(matrix, visited, x, y + 1); // right cell
    edge_count += dfs(matrix, visited, x, y - 1); // left cell

    edge_count
}
