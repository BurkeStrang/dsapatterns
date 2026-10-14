"""
Given an m x n grid of characters board and a string word,
return true if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: word="ABCCED", board:
  { 'A', 'B', 'C', 'E' },
  { 'S', 'F', 'C', 'S' },
  { 'A', 'D', 'E', 'E' }
Output: true
Explanation: The word exists in the board:
-> { 'A', 'B', 'C', 'E' },
-> { 'S', 'F', 'C', 'S' },
-> { 'A', 'D', 'E', 'E' }

Example 2:
Input: word="SEE", board:

  { 'A', 'B', 'C', 'E' },
  { 'S', 'F', 'C', 'S' },
  { 'A', 'D', 'E', 'E' }
Output: true
Explanation: The word exists in the board:
-> { 'A', 'B', 'C', 'E' },
-> { 'S', 'F', 'C', 'S' },
-> { 'A', 'D', 'E', 'E' }

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
"""


def dfs(board: list[list[str]], word: str, i: int, j: int, k: int) -> bool:
    # the search steps one cell past every edge, so i and j may be -1 or one
    # past the end
    if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
        return False
    if board[i][j] != word[k]:
        return False
    if k == len(word) - 1:
        return True

    # mark the cell as used on this path, and put its letter back afterwards
    tmp = board[i][j]
    board[i][j] = "/"
    res = (
        dfs(board, word, i + 1, j, k + 1)
        or dfs(board, word, i - 1, j, k + 1)
        or dfs(board, word, i, j + 1, k + 1)
        or dfs(board, word, i, j - 1, k + 1)
    )
    board[i][j] = tmp
    return res


def exist(board: list[list[str]], word: str) -> bool:
    for i in range(len(board)):
        for j in range(len(board[0])):
            if dfs(board, word, i, j, 0):
                return True
    return False
