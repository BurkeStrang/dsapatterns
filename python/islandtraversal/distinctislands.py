"""
You are given a 2D matrix containing only 1s (land) and 0s (water).
An island is a connected set of 1s (land) and is surrounded by either an edge
or 0s (water).
Each cell is considered connected to other cells horizontally or vertically
(not diagonally).
Two islands are considered the same if and only if they can be translated
(not rotated or reflected) to equal each other.
Write a function to find the number of distinct islands in the given matrix.
"""

from islandtraversal.shared import in_bounds


def traverse_island_dfs(
    matrix: list[list[int]],
    visited: list[list[bool]],
    x: int,
    y: int,
    path: list[str],
    direction: str,
) -> None:
    if not in_bounds(matrix, x, y):
        return  # return if it is not a valid cell
    if matrix[x][y] == 0 or visited[x][y]:
        return  # return if it is a water cell or is visited

    visited[x][y] = True  # mark the cell visited
    path.append(direction)

    # recursively visit all neighboring cells (horizontally & vertically)
    traverse_island_dfs(matrix, visited, x + 1, y, path, "D")  # down
    traverse_island_dfs(matrix, visited, x - 1, y, path, "U")  # up
    traverse_island_dfs(matrix, visited, x, y + 1, path, "R")  # right
    traverse_island_dfs(matrix, visited, x, y - 1, path, "L")  # left

    path.append("B")  # back


def find_distinct_islands_dfs(matrix: list[list[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    visited = [[False] * cols for _ in range(rows)]
    islands_set: set[str] = set()
    for i in range(rows):
        for j in range(cols):
            # only if the cell is a land and not visited
            if matrix[i][j] == 1 and not visited[i][j]:
                island_traversal: list[str] = []
                traverse_island_dfs(
                    matrix, visited, i, j, island_traversal, "O"
                )  # origin
                islands_set.add("".join(island_traversal))
    return len(islands_set)
