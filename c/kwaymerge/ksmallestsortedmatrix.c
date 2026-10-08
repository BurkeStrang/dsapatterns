#include "common/heap.h"
#include "common/list.h"

// Given an N * N matrix where each row and column is sorted in ascending order,
// find the Kth smallest element in the matrix.
// Example 1:
// Input: Matrix=[
//     [2, 6, 8],
//     [3, 7, 10],
//     [5, 8, 11]
//   ],
//   K=5
// Output: 7
// Explanation: The 5th smallest number in the matrix is 7.

// Point is a cell of the matrix, with the number found there.
typedef struct
{
    int value;
    int row;
    int col;
} Point;

// min-heap order: the smallest number comes first
bool point_value_less
(
    const void *a,
    const void *b
)
{
    return ((const Point *)a)->value < ((const Point *)b)->value;
}

// find_kth_smallest_point finds the Kth smallest element in a matrix
int find_kth_smallest_point
(
    const IntMatrix *matrix,
    int k
)
{
    Heap min_heap = heap_new(sizeof(Point), point_value_less);

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int i = 0; i < matrix->len && i < k; i++)
    {
        heap_push(&min_heap, &(Point){matrix->rows[i].items[0], i, 0});
    }

    // take the smallest (top) element form the min heap, if the running count
    // is equal to k return the number. if the row of the top element has more
    // elements, add the next element to the heap
    int number_count = 0;
    int result = 0;
    while (min_heap.len > 0)
    {
        Point node;
        heap_pop(&min_heap, &node);
        result = node.value;
        number_count++;
        if (number_count == k)
        {
            break;
        }

        node.col++;
        if (matrix->rows[0].len > node.col)
        {
            node.value = matrix->rows[node.row].items[node.col];
            heap_push(&min_heap, &node);
        }
    }

    heap_free(&min_heap);
    return result;
}
