#include "islandtraversal/shared.h"

int get_island_area
(
    IntMatrix *matrix,
    int x,
    int y
)
{
    if (x < 0 || x >= matrix->len || y < 0 || y >= matrix->rows[0].len)
    {
        return 0; // return, if it is not a valid cell
    }
    if (CELL(matrix, x, y) == 0)
    {
        return 0; // return, if it is a water cell
    }

    CELL(matrix, x, y) = 0; // mark the cell visited by making it a water cell

    int area = 1; // counting the current cell
    // recursively visit all neighboring cells (horizontally & vertically)
    area += get_island_area(matrix, x + 1, y); // lower cell
    area += get_island_area(matrix, x - 1, y); // upper cell
    area += get_island_area(matrix, x, y + 1); // right cell
    area += get_island_area(matrix, x, y - 1); // left cell

    return area;
}

int max_area_of_island
(
    IntMatrix *matrix
)
{
    int rows = matrix->len;
    int cols = matrix->rows[0].len;
    int biggest_island_area = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (CELL(matrix, i, j) == 1)
            { // only if the cell is a land
                // we have found an island
                int area = get_island_area(matrix, i, j);
                if (area > biggest_island_area)
                {
                    biggest_island_area = area;
                }
            }
        }
    }

    return biggest_island_area;
}
