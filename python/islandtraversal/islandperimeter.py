"""
You are given a 2D matrix containing only 1s (land) and 0s (water).
An island is a connected set of 1s (land) and is surrounded by either an edge
or 0s (water).
Each cell is considered connected to other cells horizontally or vertically
(not diagonally).
There are no lakes on the island, so the water inside the island is not
connected to the water around it.
A cell is a square with a side length of 1.
The given matrix has only one island, write a function to find the perimeter
of that island.
"""

from islandtraversal.shared import in_bounds


def dfs(
    matrix: list[list[int]], visited: list[list[bool]], x: int, y: int
) -> int:
    if not in_bounds(matrix, x, y):
        # returning 1, since this a boundary cell initiated this DFS call
        return 1
    if matrix[x][y] == 0:
        # returning 1, because of the shared side b/w a water and a land cell
        return 1
    if visited[x][y]:
        return 0  # we have already taken care of this cell

    visited[x][y] = True  # mark the cell visited
    edge_count = 0
    # recursively visit all neighboring cells (horizontally & vertically)
    edge_count += dfs(matrix, visited, x + 1, y)  # lower cell
    edge_count += dfs(matrix, visited, x - 1, y)  # upper cell
    edge_count += dfs(matrix, visited, x, y + 1)  # right cell
    edge_count += dfs(matrix, visited, x, y - 1)  # left cell
    return edge_count


def find_island_perimeter(matrix: list[list[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    visited = [[False] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            # only if the cell is a land and not visited
            if matrix[i][j] == 1 and not visited[i][j]:
                return dfs(matrix, visited, i, j)
    return 0
