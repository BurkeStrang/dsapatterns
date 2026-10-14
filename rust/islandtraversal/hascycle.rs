use super::shared::in_bounds;

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

pub fn has_cycle(matrix: &[Vec<char>]) -> bool {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut visited = vec![vec![false; cols]; rows];

    for i in 0..rows {
        for j in 0..cols {
            let (x, y) = (i as i32, j as i32);
            if dfs_cycle(matrix, &mut visited, x, y, x, y, matrix[i][j]) {
                return true;
            }
        }
    }
    false
}

fn dfs_cycle(
    matrix: &[Vec<char>],
    visited: &mut [Vec<bool>],
    x: i32,
    y: i32,
    prev_x: i32,
    prev_y: i32,
    org_char: char,
) -> bool {
    if !in_bounds(matrix, x, y) || matrix[x as usize][y as usize] != org_char {
        return false;
    }

    if visited[x as usize][y as usize] {
        return true;
    }

    visited[x as usize][y as usize] = true;

    // visit every neighbor except the cell we just came from
    if x + 1 != prev_x && dfs_cycle(matrix, visited, x + 1, y, x, y, org_char) {
        return true;
    }
    if x - 1 != prev_x && dfs_cycle(matrix, visited, x - 1, y, x, y, org_char) {
        return true;
    }
    if y + 1 != prev_y && dfs_cycle(matrix, visited, x, y + 1, x, y, org_char) {
        return true;
    }
    if y - 1 != prev_y && dfs_cycle(matrix, visited, x, y - 1, x, y, org_char) {
        return true;
    }

    false
}
