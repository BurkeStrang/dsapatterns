use super::shared::in_bounds;

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

pub fn count_closed_islands(matrix: &[Vec<i32>]) -> usize {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut count_closed_islands = 0;
    let mut visited = vec![vec![false; cols]; rows];

    for i in 0..rows {
        for j in 0..cols {
            // only if the cell is a land and not visited
            if matrix[i][j] == 1
                && !visited[i][j]
                && is_closed_island_dfs(
                    matrix,
                    &mut visited,
                    i as i32,
                    j as i32,
                )
            {
                count_closed_islands += 1;
            }
        }
    }

    count_closed_islands
}

// is_closed_island_dfs checks if the island is closed using DFS
fn is_closed_island_dfs(
    matrix: &[Vec<i32>],
    visited: &mut [Vec<bool>],
    x: i32,
    y: i32,
) -> bool {
    if !in_bounds(matrix, x, y) {
        return false; // returning false since the island is touching an edge
    }
    let (row, col) = (x as usize, y as usize);
    if matrix[row][col] == 0 || visited[row][col] {
        return true; // returning true as the island is surrounded by water
    }

    visited[row][col] = true; // mark the cell visited

    let mut is_closed = true;
    // recursively visit all neighboring cells (horizontally & vertically);
    // like the Go version, once the island is known to be open the rest of
    // its cells are left for a later call
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x + 1, y);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x - 1, y);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x, y + 1);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x, y - 1);

    is_closed
}
