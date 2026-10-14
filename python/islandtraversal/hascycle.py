"""
You are given a 2D matrix containing different characters,
you need to find if there exists any cycle consisting of the same character
in the matrix.
A cycle is a path in the matrix that starts and ends at the same cell and has
four or more cells.
From a given cell,
you can move to one of the cells adjacent to it - in one of the four
directions
(up, down, left, or right), if it has the same character value of the current
cell.
Write a function to find if the matrix has a cycle.
"""

from islandtraversal.shared import in_bounds


def dfs_cycle(
    matrix: list[list[str]],
    visited: list[list[bool]],
    x: int,
    y: int,
    prev_x: int,
    prev_y: int,
    org_char: str,
) -> bool:
    if not in_bounds(matrix, x, y) or matrix[x][y] != org_char:
        return False
    if visited[x][y]:
        return True
    visited[x][y] = True

    # visit every neighbor except the cell we just came from
    if x + 1 != prev_x and dfs_cycle(matrix, visited, x + 1, y, x, y, org_char):
        return True
    if x - 1 != prev_x and dfs_cycle(matrix, visited, x - 1, y, x, y, org_char):
        return True
    if y + 1 != prev_y and dfs_cycle(matrix, visited, x, y + 1, x, y, org_char):
        return True
    return y - 1 != prev_y and dfs_cycle(
        matrix, visited, x, y - 1, x, y, org_char
    )


def has_cycle(matrix: list[list[str]]) -> bool:
    rows = len(matrix)
    cols = len(matrix[0])
    visited = [[False] * cols for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            if dfs_cycle(matrix, visited, i, j, i, j, matrix[i][j]):
                return True
    return False
