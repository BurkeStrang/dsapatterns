#include "common/heap.h"
#include "topkelements/shared.h"

// Given an array of points in a 2D plane, find ‘K’ closest points to the
// origin.
//
// Example 1:
// Input: points = [[1,2],[1,3]], K = 1
// Output: [[1,2]]
// Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
// The Euclidean distance between (1, 3) and the origin is sqrt(10).
// Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
//
// Example 2:
// Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
// Output: [[1, 3], [2, -1]]

// max-heap order: the point furthest from the origin comes first
bool point_further
(
    const void *a,
    const void *b
)
{
    return dist_from_origin(*(const Point *)a) >
           dist_from_origin(*(const Point *)b);
}

// The k closest points are returned in a new array that the caller must
// free.
Point *find_closest_points
(
    const Point *points,
    int points_len,
    int k
)
{
    Heap max_point_heap = heap_new(sizeof(Point), point_further);

    // put first 'k' points in the max heap
    for (int i = 0; i < k; i++)
    {
        heap_push(&max_point_heap, &points[i]);
    }

    // go through the remaining points of the input array, if a point is
    // closer to the origin than the top point of the max-heap, remove the top
    // point from heap and add the point from the input array
    for (int i = k; i < points_len; i++)
    {
        Point top = *(Point *)heap_top(&max_point_heap);
        if (dist_from_origin(points[i]) < dist_from_origin(top))
        {
            heap_pop(&max_point_heap, NULL);
            heap_push(&max_point_heap, &points[i]);
        }
    }

    // the heap has 'k' points closest to the origin, return them in an array
    Point *result = malloc((size_t)k * sizeof(Point));
    for (int i = 0; i < k; i++)
    {
        heap_pop(&max_point_heap, &result[i]);
    }

    heap_free(&max_point_heap);
    return result;
}
