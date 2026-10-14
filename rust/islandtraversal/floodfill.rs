use super::shared::in_bounds;

// Any image can be represented by a 2D integer array (i.e., a matrix)
// where each cell represents the pixel value of the image.
// Flood fill algorithm takes a starting cell (i.e., a pixel) and a color.
// The given color is applied to all horizontally and vertically connected
// cells with the same color as that of the starting cell.
// Recursively, the algorithm fills cells with the new color until
// it encounters a cell with a different color than the starting cell.
// Given a matrix, a starting cell, and a color, flood fill the matrix.
//
// Example 1:
// Input: matrix =  [0,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,0,1,1]
// starting cell = (1, 3)
// new color = 2
// Output: new matrix = [0,0,0,2,2]
//                      [1,0,0,2,2]
//                      [1,0,0,2,2]
//
// Example 2:
// Input: matrix =  [0,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,1,1,1]
// starting cell = (3, 2)
// new color = 5
// Output: new matrix = [0,0,0,5,5]
//                      [1,0,0,5,5]
//                      [1,0,0,5,5]
//                      [1,0,5,5,5]
//
// Constraints:
// m == matrix.length
// n == - m == matrix[i].length
// 1 <= m, n <= 50
// 0 <= - m == matrix[i][j], color < 216
// 0 <= x < m
// 0 <= y < n

pub fn flood_fill(matrix: &mut [Vec<i32>], x: usize, y: usize, new_color: i32) {
    if x >= matrix.len() || y >= matrix[0].len() {
        return;
    }

    if matrix[x][y] == 1 {
        flood_fill_dfs(matrix, x as i32, y as i32, new_color);
    }
}

fn flood_fill_dfs(matrix: &mut [Vec<i32>], x: i32, y: i32, new_color: i32) {
    matrix[x as usize][y as usize] = new_color;

    let moves = [(1, 0), (-1, 0), (0, 1), (0, -1)];
    for (dx, dy) in moves {
        let mx = x + dx;
        let my = y + dy;
        let matched =
            in_bounds(matrix, mx, my) && matrix[mx as usize][my as usize] == 1;
        if matched {
            flood_fill_dfs(matrix, mx, my, new_color);
        }
    }
}
