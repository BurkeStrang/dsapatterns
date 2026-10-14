"""
Any image can be represented by a 2D integer array (i.e., a matrix)
where each cell represents the pixel value of the image.
Flood fill algorithm takes a starting cell (i.e., a pixel) and a color.
The given color is applied to all horizontally and vertically connected
cells with the same color as that of the starting cell.
Recursively, the algorithm fills cells with the new color until
it encounters a cell with a different color than the starting cell.
Given a matrix, a starting cell, and a color, flood fill the matrix.

Example 1:
Input: matrix =  [0,0,0,1,1]
                 [1,0,0,1,1]
                 [1,0,0,1,1]
starting cell = (1, 3)
new color = 2
Output: new matrix = [0,0,0,2,2]
                     [1,0,0,2,2]
                     [1,0,0,2,2]

Example 2:
Input: matrix =  [0,0,0,1,1]
                 [1,0,0,1,1]
                 [1,0,0,1,1]
                 [1,0,1,1,1]
starting cell = (3, 2)
new color = 5
Output: new matrix = [0,0,0,5,5]
                     [1,0,0,5,5]
                     [1,0,0,5,5]
                     [1,0,5,5,5]

Constraints:
m == matrix.length
n == - m == matrix[i].length
1 <= m, n <= 50
0 <= - m == matrix[i][j], color < 216
0 <= x < m
0 <= y < n
"""

from islandtraversal.shared import in_bounds

MOVES = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def flood_fill_dfs(
    matrix: list[list[int]], x: int, y: int, new_color: int
) -> None:
    matrix[x][y] = new_color
    for dx, dy in MOVES:
        mx = x + dx
        my = y + dy
        if in_bounds(matrix, mx, my) and matrix[mx][my] == 1:
            flood_fill_dfs(matrix, mx, my, new_color)


def flood_fill(matrix: list[list[int]], x: int, y: int, new_color: int) -> None:
    if not in_bounds(matrix, x, y):
        return
    if matrix[x][y] == 1:
        flood_fill_dfs(matrix, x, y, new_color)
