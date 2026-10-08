#include <stdbool.h>
#include <string.h>

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

// board holds one string per row; cells are changed while searching and put
// back afterwards.
bool dfs
(
    char **board,
    int rows,
    int cols,
    const char *word,
    int i,
    int j,
    int k
)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
    {
        return false;
    }
    if (k == (int)strlen(word) - 1)
    {
        return true;
    }
    char tmp = board[i][j];
    board[i][j] = '/';
    bool res = dfs(board, rows, cols, word, i + 1, j, k + 1) ||
               dfs(board, rows, cols, word, i - 1, j, k + 1) ||
               dfs(board, rows, cols, word, i, j + 1, k + 1) ||
               dfs(board, rows, cols, word, i, j - 1, k + 1);
    board[i][j] = tmp;
    return res;
}

bool exist
(
    char **board,
    int rows,
    const char *word
)
{
    int cols = (int)strlen(board[0]);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (dfs(board, rows, cols, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}
