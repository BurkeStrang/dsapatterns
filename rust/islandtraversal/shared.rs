/// Reports whether (x, y) is a cell of the matrix. The traversals step one
/// cell past every edge, so the coordinates are signed and may be -1.
pub fn in_bounds<T>(matrix: &[Vec<T>], x: i32, y: i32) -> bool {
    x >= 0
        && (x as usize) < matrix.len()
        && y >= 0
        && (y as usize) < matrix[0].len()
}
