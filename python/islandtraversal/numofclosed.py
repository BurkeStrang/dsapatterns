"""
You are given a 2D matrix containing only 1s (land) and 0s (water).
An island is a connected set of 1s (land) and is surrounded by either an edge
or 0s (water).
Each cell is considered connected to other cells horizontally or vertically
(not diagonally).

A closed island is an island that is totally surrounded by 0s (i.e., water).
This means all horizontally and vertically connected cells of a closed island
are water.
This also means that, by definition, a closed island can't touch an edge
(as then the edge cells are not connected to any water cell).

Write a function to find the number of closed islands in the given matrix.

Example 1
Input: matrix = [1,1,1,1,1,1,1]
                                                                 [0,0,1,0,0,0,1]
                                                                 [0,0,1,0,0,1,0]
                                                                 [0,0,1,0,0,1,0]
                                                                 [0,0,0,0,0,0,0]
Output: 1 Explanation: The given matrix has two islands, but only the
highlighted island is a closed island.
The other island is touching the boundary that's why is is not considered a
closed island.

Example 2
Input: matrix = [1,1,1,1,1,1,1,0]
                                                                 [1,0,0,0,0,1,1,0]
                                                                 [0,0,1,0,1,0,1,0]
                                                                 [0,0,0,0,0,0,1,0]
Output: 2
Explanation: The given matrix has two islands and both of them are closed
islands.

Constraints:

0 <= grid[i][j] <=1
"""

from islandtraversal.shared import in_bounds


def is_closed_island_dfs(
    matrix: list[list[int]], visited: list[list[bool]], x: int, y: int
) -> bool:
    """Checks if the island is closed using DFS."""
    if not in_bounds(matrix, x, y):
        return False  # returning false since the island is touching an edge
    if matrix[x][y] == 0 or visited[x][y]:
        return True  # returning true as the island is surrounded by water

    visited[x][y] = True  # mark the cell visited

    # recursively visit all neighboring cells (horizontally & vertically).
    # visit every neighbor even after one reaches an edge: stopping early
    # leaves the rest of the island unvisited, and it is counted again later
    down = is_closed_island_dfs(matrix, visited, x + 1, y)
    up = is_closed_island_dfs(matrix, visited, x - 1, y)
    right = is_closed_island_dfs(matrix, visited, x, y + 1)
    left = is_closed_island_dfs(matrix, visited, x, y - 1)
    return down and up and right and left


def count_closed_islands(matrix: list[list[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    count_closed_islands = 0
    visited = [[False] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            # only if the cell is a land and not visited
            if (
                matrix[i][j] == 1
                and not visited[i][j]
                and is_closed_island_dfs(matrix, visited, i, j)
            ):
                count_closed_islands += 1
    return count_closed_islands
