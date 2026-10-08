// Shared helpers for the island traversal problems.
#ifndef DSAPATTERNS_ISLANDTRAVERSAL_SHARED_H
#define DSAPATTERNS_ISLANDTRAVERSAL_SHARED_H

#include "common/list.h"

#include <stdbool.h>
#include <stdlib.h>

// CELL is the value at row x, column y of a matrix.
#define CELL(matrix, x, y) ((matrix)->rows[(x)].items[(y)])

// Visited records which cells of a grid have been seen. Free its cells
// when done.
typedef struct
{
    bool *cells;
    int cols;
} Visited;

static inline Visited visited_new
(
    int rows,
    int cols
)
{
    Visited visited = {calloc((size_t)rows * (size_t)cols, sizeof(bool)), cols};
    return visited;
}

// SEEN is the visited flag for row x, column y.
#define SEEN(visited, x, y) ((visited)->cells[(x) * (visited)->cols + (y)])

#endif
