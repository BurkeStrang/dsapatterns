use std::collections::HashSet;

use super::shared::in_bounds;

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

pub fn find_distinct_islands_dfs(matrix: &[Vec<i32>]) -> usize {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut visited = vec![vec![false; cols]; rows];
    let mut islands_set = HashSet::new();

    for i in 0..rows {
        for j in 0..cols {
            // only if the cell is a land and not visited
            if matrix[i][j] == 1 && !visited[i][j] {
                let mut island_traversal = String::new();
                traverse_island_dfs(
                    matrix,
                    &mut visited,
                    i as i32,
                    j as i32,
                    &mut island_traversal,
                    'O', // origin
                );
                islands_set.insert(island_traversal);
            }
        }
    }
    islands_set.len()
}

fn traverse_island_dfs(
    matrix: &[Vec<i32>],
    visited: &mut [Vec<bool>],
    x: i32,
    y: i32,
    path: &mut String,
    direction: char,
) {
    if !in_bounds(matrix, x, y) {
        return; // return if it is not a valid cell
    }
    let (row, col) = (x as usize, y as usize);
    if matrix[row][col] == 0 || visited[row][col] {
        return; // return if it is a water cell or is visited
    }

    visited[row][col] = true; // mark the cell visited
    path.push(direction);

    // recursively visit all neighboring cells (horizontally & vertically)
    traverse_island_dfs(matrix, visited, x + 1, y, path, 'D'); // down
    traverse_island_dfs(matrix, visited, x - 1, y, path, 'U'); // up
    traverse_island_dfs(matrix, visited, x, y + 1, path, 'R'); // right
    traverse_island_dfs(matrix, visited, x, y - 1, path, 'L'); // left

    path.push('B'); // back
}
