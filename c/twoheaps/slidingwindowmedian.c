#include "common/heap.h"

// The two heaps hold the current window: max_heap has the smaller half of
// its numbers and min_heap the larger half.
typedef struct
{
    Heap max_heap;
    Heap min_heap;
} Window;

void rebalance_heaps
(
    Window *window
)
{
    if (window->max_heap.len > window->min_heap.len + 1)
    {
        int_heap_push(&window->min_heap, int_heap_pop(&window->max_heap));
    }
    else if (window->max_heap.len < window->min_heap.len)
    {
        int_heap_push(&window->max_heap, int_heap_pop(&window->min_heap));
    }
}

// remove_from_heap takes one copy of target out of the heap, if it is there.
void remove_from_heap
(
    Heap *heap,
    int target
)
{
    for (int i = 0; i < heap->len; i++)
    {
        if (*(int *)heap_at(heap, i) == target)
        {
            heap_remove(heap, i, NULL);
            return;
        }
    }
}

// The medians are returned in a new array of nums_len - k + 1 numbers that
// the caller must free.
double *find_sliding_window_median
(
    const int *nums,
    int nums_len,
    int k
)
{
    double *result = malloc((size_t)(nums_len - k + 1) * sizeof(double));
    Window window = {int_max_heap_new(), int_min_heap_new()};

    for (int i = 0; i < nums_len; i++)
    {
        if (window.max_heap.len == 0 ||
            int_heap_top(&window.max_heap) >= nums[i])
        {
            int_heap_push(&window.max_heap, nums[i]);
        }
        else
        {
            int_heap_push(&window.min_heap, nums[i]);
        }

        rebalance_heaps(&window);

        if (i - k + 1 >= 0)
        {
            if (window.max_heap.len == window.min_heap.len)
            {
                result[i - k + 1] = (int_heap_top(&window.max_heap) +
                                     int_heap_top(&window.min_heap)) /
                                    2.0;
            }
            else
            {
                result[i - k + 1] = int_heap_top(&window.max_heap);
            }

            int element_to_be_removed = nums[i - k + 1];
            if (element_to_be_removed <= int_heap_top(&window.max_heap))
            {
                remove_from_heap(&window.max_heap, element_to_be_removed);
            }
            else
            {
                remove_from_heap(&window.min_heap, element_to_be_removed);
            }

            rebalance_heaps(&window);
        }
    }

    heap_free(&window.max_heap);
    heap_free(&window.min_heap);
    return result;
}
