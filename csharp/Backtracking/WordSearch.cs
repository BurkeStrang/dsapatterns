namespace DsaPatterns.Backtracking;

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

internal static class WordSearch
{
    internal static bool Exist(char[][] board, string word)
    {
        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                if (Dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    private static bool Dfs(char[][] board, string word, int i, int j, int k)
    {
        if (
            i < 0
            || i >= board.Length
            || j < 0
            || j >= board[0].Length
            || board[i][j] != word[k]
        )
        {
            return false;
        }

        if (k == word.Length - 1)
        {
            return true;
        }

        char tmp = board[i][j];
        board[i][j] = '/';
        bool res =
            Dfs(board, word, i + 1, j, k + 1)
            || Dfs(board, word, i - 1, j, k + 1)
            || Dfs(board, word, i, j + 1, k + 1)
            || Dfs(board, word, i, j - 1, k + 1);
        board[i][j] = tmp;
        return res;
    }
}
