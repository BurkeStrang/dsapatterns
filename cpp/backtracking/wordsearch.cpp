#include <string>
#include <vector>

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

// the search steps one cell past every edge, so i and j may be -1 or one past
// the end
bool dfs(std::vector<std::string> &board, const std::string &word, int i, int j,
         int k)
{
    if (i < 0 || i >= std::ssize(board) || j < 0 || j >= std::ssize(board[0]))
    {
        return false;
    }
    if (board[i][j] != word[k])
    {
        return false;
    }

    if (k == std::ssize(word) - 1)
    {
        return true;
    }

    // mark the cell as used on this path, and put its letter back afterwards
    char tmp = board[i][j];
    board[i][j] = '/';

    bool res = dfs(board, word, i + 1, j, k + 1) ||
               dfs(board, word, i - 1, j, k + 1) ||
               dfs(board, word, i, j + 1, k + 1) ||
               dfs(board, word, i, j - 1, k + 1);

    board[i][j] = tmp;
    return res;
}

bool exist(std::vector<std::string> &board, const std::string &word)
{
    for (int i = 0; i < std::ssize(board); i++)
    {
        for (int j = 0; j < std::ssize(board[0]); j++)
        {
            if (dfs(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}
