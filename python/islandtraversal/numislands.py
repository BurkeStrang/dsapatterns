"""
Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
count the number of islands in it.

An island is a connected set of 1s (land) and is surrounded by either an edge
or 0s (water).
Each cell is considered connected to other cells horizontally or vertically
(not diagonally).

Example 1
Input: matrix = [1,1,1,0,0],
                                                                 [0,1,0,0,1],
                                                                 [0,0,1,1,0],
                                                                 [0,0,1,0,0],
                                                                 [0,0,1,0,0]
Output: 3

Example 2
Input: matrix = [1,1,0,0,0],
                                                                 [0,1,0,0,0],
                                                                 [0,1,0,0,0],
                                                                 [0,1,0,0,0],
Output: 1

Image
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
"""

from islandtraversal.shared import in_bounds


def visit_island_dfs(matrix: list[list[int]], x: int, y: int) -> None:
    """Performs a depth-first search to visit all parts of an island."""
    if not in_bounds(matrix, x, y):
        return  # return, if it is not a valid cell
    if matrix[x][y] == 0:
        return  # return, if it is a water cell

    # mark the cell visited by making it a water cell
    matrix[x][y] = 0

    # recursively visit all neighboring cells (horizontally & vertically)
    visit_island_dfs(matrix, x + 1, y)  # lower cell
    visit_island_dfs(matrix, x - 1, y)  # upper cell
    visit_island_dfs(matrix, x, y + 1)  # right cell
    visit_island_dfs(matrix, x, y - 1)  # left cell


def count_islands(matrix: list[list[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    total_islands = 0
    for i in range(rows):
        for j in range(cols):
            # only if the cell is a land
            if matrix[i][j] == 1:
                # we have found an island
                total_islands += 1
                visit_island_dfs(matrix, i, j)
    return total_islands
