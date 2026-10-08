#include "common/heap.h"

// Interval represents an interval with a start and an end.
typedef struct
{
    int start;
    int end;
} Interval;

// IndexedTime pairs an interval's index with its start or end time.
typedef struct
{
    int time;
    int index;
} IndexedTime;

// max-heap order: the latest time comes first
bool indexed_time_greater
(
    const void *a,
    const void *b
)
{
    return ((const IndexedTime *)a)->time > ((const IndexedTime *)b)->time;
}

// The result has one entry per interval and must be freed by the caller.
int *find_next_interval
(
    const Interval *intervals,
    int n
)
{
    // max-heaps of interval indexes, ordered by start and by end times
    Heap max_start_heap = heap_new(sizeof(IndexedTime), indexed_time_greater);
    Heap max_end_heap = heap_new(sizeof(IndexedTime), indexed_time_greater);
    int *result = malloc((size_t)n * sizeof(int));

    // Initialize heaps
    for (int i = 0; i < n; i++)
    {
        heap_push(&max_start_heap, &(IndexedTime){intervals[i].start, i});
        heap_push(&max_end_heap, &(IndexedTime){intervals[i].end, i});
    }

    // Iterate through intervals to find the next interval
    for (int k = 0; k < n; k++)
    {
        IndexedTime top_end;
        heap_pop(&max_end_heap, &top_end);
        result[top_end.index] = -1; // Default to -1
        if (((IndexedTime *)heap_top(&max_start_heap))->time >= top_end.time)
        {
            IndexedTime top_start;
            heap_pop(&max_start_heap, &top_start);
            while (max_start_heap.len > 0 &&
                   ((IndexedTime *)heap_top(&max_start_heap))->time >=
                       top_end.time)
            {
                heap_pop(&max_start_heap, &top_start);
            }
            result[top_end.index] = top_start.index;
            // Put it back as it could be next for other intervals
            heap_push(&max_start_heap, &top_start);
        }
    }

    heap_free(&max_start_heap);
    heap_free(&max_end_heap);
    return result;
}
