use super::shared::in_bounds;

// Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
// find the biggest island in it. Write a function to return the area of the
// biggest island. An island is a connected set of 1s (land) and is surrounded
// by either an edge or 0s (water). Each cell is considered connected to other
// cells horizontally or vertically (not diagonally).

pub fn max_area_of_island(matrix: &mut [Vec<i32>]) -> usize {
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut biggest_island_area = 0;

    for i in 0..rows {
        for j in 0..cols {
            // only if the cell is a land
            if matrix[i][j] == 1 {
                // we have found an island
                let area = get_island_area(matrix, i as i32, j as i32);
                biggest_island_area = biggest_island_area.max(area);
            }
        }
    }

    biggest_island_area
}

fn get_island_area(matrix: &mut [Vec<i32>], x: i32, y: i32) -> usize {
    if !in_bounds(matrix, x, y) {
        return 0; // return, if it is not a valid cell
    }
    if matrix[x as usize][y as usize] == 0 {
        return 0; // return, if it is a water cell
    }

    // mark the cell visited by making it a water cell
    matrix[x as usize][y as usize] = 0;

    let mut area = 1; // counting the current cell
    // recursively visit all neighboring cells (horizontally & vertically)
    area += get_island_area(matrix, x + 1, y); // lower cell
    area += get_island_area(matrix, x - 1, y); // upper cell
    area += get_island_area(matrix, x, y + 1); // right cell
    area += get_island_area(matrix, x, y - 1); // left cell

    area
}
