// Given an m x n grid of characters board and a string word,
// return true if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// Example 1:
// Input: word="ABCCED", board:
//   { 'A', 'B', 'C', 'E' },
//   { 'S', 'F', 'C', 'S' },
//   { 'A', 'D', 'E', 'E' }
// Output: true
// Explanation: The word exists in the board:
// -> { 'A', 'B', 'C', 'E' },
// -> { 'S', 'F', 'C', 'S' },
// -> { 'A', 'D', 'E', 'E' }
//
// Example 2:
// Input: word="SEE", board:
//
//   { 'A', 'B', 'C', 'E' },
//   { 'S', 'F', 'C', 'S' },
//   { 'A', 'D', 'E', 'E' }
// Output: true
// Explanation: The word exists in the board:
// -> { 'A', 'B', 'C', 'E' },
// -> { 'S', 'F', 'C', 'S' },
// -> { 'A', 'D', 'E', 'E' }
//
// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

pub fn exist(board: &mut [Vec<u8>], word: &str) -> bool {
    let word = word.as_bytes();
    for i in 0..board.len() {
        for j in 0..board[0].len() {
            if dfs(board, word, i as i32, j as i32, 0) {
                return true;
            }
        }
    }
    false
}

// the search steps one cell past every edge, so the coordinates are signed
// and may be -1
fn dfs(board: &mut [Vec<u8>], word: &[u8], i: i32, j: i32, k: usize) -> bool {
    if i < 0
        || i as usize >= board.len()
        || j < 0
        || j as usize >= board[0].len()
    {
        return false;
    }
    let (row, col) = (i as usize, j as usize);
    if board[row][col] != word[k] {
        return false;
    }

    if k == word.len() - 1 {
        return true;
    }

    // mark the cell as used on this path, and put its letter back afterwards
    let tmp = board[row][col];
    board[row][col] = b'/';

    let res = dfs(board, word, i + 1, j, k + 1)
        || dfs(board, word, i - 1, j, k + 1)
        || dfs(board, word, i, j + 1, k + 1)
        || dfs(board, word, i, j - 1, k + 1);

    board[row][col] = tmp;
    res
}
