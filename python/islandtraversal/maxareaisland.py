"""
Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
find the biggest island in it. Write a function to return the area of the
biggest island. An island is a connected set of 1s (land) and is surrounded
by either an edge or 0s (water). Each cell is considered connected to other
cells horizontally or vertically (not diagonally).
"""

from islandtraversal.shared import in_bounds


def get_island_area(matrix: list[list[int]], x: int, y: int) -> int:
    if not in_bounds(matrix, x, y):
        return 0  # return, if it is not a valid cell
    if matrix[x][y] == 0:
        return 0  # return, if it is a water cell

    # mark the cell visited by making it a water cell
    matrix[x][y] = 0

    area = 1  # counting the current cell
    # recursively visit all neighboring cells (horizontally & vertically)
    area += get_island_area(matrix, x + 1, y)  # lower cell
    area += get_island_area(matrix, x - 1, y)  # upper cell
    area += get_island_area(matrix, x, y + 1)  # right cell
    area += get_island_area(matrix, x, y - 1)  # left cell
    return area


def max_area_of_island(matrix: list[list[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    biggest_island_area = 0
    for i in range(rows):
        for j in range(cols):
            # only if the cell is a land
            if matrix[i][j] == 1:
                # we have found an island
                area = get_island_area(matrix, i, j)
                biggest_island_area = max(biggest_island_area, area)
    return biggest_island_area
