#include "common/heap.h"

// Median keeps the smaller half of the numbers in a max-heap and the larger
// half in a min-heap, so the middle is always at the top of one or both.
typedef struct
{
    Heap max_heap;
    Heap min_heap;
} Median;

Median median_new(void)
{
    Median median = {int_max_heap_new(), int_min_heap_new()};
    return median;
}

void median_free
(
    Median *median
)
{
    heap_free(&median->max_heap);
    heap_free(&median->min_heap);
}

void insert_num
(
    Median *median,
    int num
)
{
    if (median->max_heap.len == 0 || int_heap_top(&median->max_heap) >= num)
    {
        int_heap_push(&median->max_heap, num);
    }
    else
    {
        int_heap_push(&median->min_heap, num);
    }

    if (median->max_heap.len > median->min_heap.len + 1)
    {
        int_heap_push(&median->min_heap, int_heap_pop(&median->max_heap));
    }
    else if (median->max_heap.len < median->min_heap.len)
    {
        int_heap_push(&median->max_heap, int_heap_pop(&median->min_heap));
    }
}

double find_median
(
    const Median *median
)
{
    if (median->max_heap.len == median->min_heap.len)
    {
        return int_heap_top(&median->max_heap) / 2.0 +
               int_heap_top(&median->min_heap) / 2.0;
    }
    return int_heap_top(&median->max_heap);
}
