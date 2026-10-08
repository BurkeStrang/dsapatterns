// Heap is a binary heap (priority queue) of fixed-size items, used where Go
// would use container/heap. The less function decides which item comes out
// first, so the same type works as a min-heap or a max-heap.
#ifndef DSAPATTERNS_COMMON_HEAP_H
#define DSAPATTERNS_COMMON_HEAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// HeapLess reports whether item a should come out of the heap before item b.
typedef bool (*HeapLess)(const void *a, const void *b);

typedef struct
{
    char *items;
    int len;
    int cap;
    size_t item_size;
    HeapLess less;
} Heap;

// heap_new makes an empty heap of items that are item_size bytes each.
static inline Heap heap_new
(
    size_t item_size,
    HeapLess less
)
{
    return (Heap){.item_size = item_size, .less = less};
}

// heap_at returns a pointer to the item at index (0 is the top of the heap).
static inline void *heap_at
(
    const Heap *heap,
    int index
)
{
    return heap->items + (size_t)index * heap->item_size;
}

// heap_top returns a pointer to the item that would come out next.
static inline void *heap_top
(
    const Heap *heap
)
{
    return heap_at(heap, 0);
}

static inline void heap_swap
(
    Heap *heap,
    int i,
    int j
)
{
    char tmp[256];
    memcpy(tmp, heap_at(heap, i), heap->item_size);
    memcpy(heap_at(heap, i), heap_at(heap, j), heap->item_size);
    memcpy(heap_at(heap, j), tmp, heap->item_size);
}

static inline void heap_sift_up
(
    Heap *heap,
    int index
)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (!heap->less(heap_at(heap, index), heap_at(heap, parent)))
        {
            break;
        }
        heap_swap(heap, index, parent);
        index = parent;
    }
}

static inline void heap_sift_down
(
    Heap *heap,
    int index
)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = left + 1;
        int first = index;
        if (left < heap->len &&
            heap->less(heap_at(heap, left), heap_at(heap, first)))
        {
            first = left;
        }
        if (right < heap->len &&
            heap->less(heap_at(heap, right), heap_at(heap, first)))
        {
            first = right;
        }
        if (first == index)
        {
            break;
        }
        heap_swap(heap, index, first);
        index = first;
    }
}

// heap_push adds a copy of *item to the heap.
static inline void heap_push
(
    Heap *heap,
    const void *item
)
{
    if (heap->len == heap->cap)
    {
        heap->cap = heap->cap < 8 ? 8 : heap->cap * 2;
        heap->items = realloc(heap->items, (size_t)heap->cap * heap->item_size);
    }
    memcpy(heap_at(heap, heap->len), item, heap->item_size);
    heap->len++;
    heap_sift_up(heap, heap->len - 1);
}

// heap_remove takes the item at index out of the heap and copies it to *out
// (out may be NULL).
static inline void heap_remove
(
    Heap *heap,
    int index,
    void *out
)
{
    if (out != NULL)
    {
        memcpy(out, heap_at(heap, index), heap->item_size);
    }
    heap->len--;
    if (index < heap->len)
    {
        memcpy(heap_at(heap, index), heap_at(heap, heap->len), heap->item_size);
        heap_sift_down(heap, index);
        heap_sift_up(heap, index);
    }
}

// heap_pop removes the top item and copies it to *out (out may be NULL).
static inline void heap_pop
(
    Heap *heap,
    void *out
)
{
    heap_remove(heap, 0, out);
}

static inline void heap_free
(
    Heap *heap
)
{
    free(heap->items);
    heap->items = NULL;
    heap->len = 0;
    heap->cap = 0;
}

// Ready-made heaps of ints.

static inline bool int_less
(
    const void *a,
    const void *b
)
{
    return *(const int *)a < *(const int *)b;
}

static inline bool int_greater
(
    const void *a,
    const void *b
)
{
    return *(const int *)a > *(const int *)b;
}

// int_min_heap_new makes a heap whose top is the smallest int.
static inline Heap int_min_heap_new(void)
{
    return heap_new(sizeof(int), int_less);
}

// int_max_heap_new makes a heap whose top is the largest int.
static inline Heap int_max_heap_new(void)
{
    return heap_new(sizeof(int), int_greater);
}

static inline void int_heap_push
(
    Heap *heap,
    int value
)
{
    heap_push(heap, &value);
}

static inline int int_heap_pop
(
    Heap *heap
)
{
    int value;
    heap_pop(heap, &value);
    return value;
}

static inline int int_heap_top
(
    const Heap *heap
)
{
    return *(const int *)heap_top(heap);
}

#endif
