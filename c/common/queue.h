// Queue is a first-in first-out queue of fixed-size items, used where Go
// would append to a slice and take items off the front.
#ifndef DSAPATTERNS_COMMON_QUEUE_H
#define DSAPATTERNS_COMMON_QUEUE_H

#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *items;
    int head; // index of the item at the front
    int len;
    int cap;
    size_t item_size;
} Queue;

// queue_new makes an empty queue of items that are item_size bytes each.
static inline Queue queue_new
(
    size_t item_size
)
{
    return (Queue){.item_size = item_size};
}

// queue_push adds a copy of *item to the back of the queue.
static inline void queue_push
(
    Queue *queue,
    const void *item
)
{
    if (queue->len == queue->cap)
    {
        int cap = queue->cap < 8 ? 8 : queue->cap * 2;
        char *items = malloc((size_t)cap * queue->item_size);
        for (int i = 0; i < queue->len; i++)
        {
            int from = (queue->head + i) % queue->cap;
            memcpy(items + (size_t)i * queue->item_size,
                   queue->items + (size_t)from * queue->item_size,
                   queue->item_size);
        }
        free(queue->items);
        queue->items = items;
        queue->head = 0;
        queue->cap = cap;
    }
    int back = (queue->head + queue->len) % queue->cap;
    memcpy(queue->items + (size_t)back * queue->item_size, item,
           queue->item_size);
    queue->len++;
}

// queue_front returns a pointer to the item at the front of the queue.
static inline void *queue_front
(
    const Queue *queue
)
{
    return queue->items + (size_t)queue->head * queue->item_size;
}

// queue_pop removes the front item and copies it to *out (out may be NULL).
static inline void queue_pop
(
    Queue *queue,
    void *out
)
{
    if (out != NULL)
    {
        memcpy(out, queue_front(queue), queue->item_size);
    }
    queue->head = (queue->head + 1) % queue->cap;
    queue->len--;
}

static inline void queue_free
(
    Queue *queue
)
{
    free(queue->items);
    queue->items = NULL;
    queue->head = 0;
    queue->len = 0;
    queue->cap = 0;
}

// Ready-made queues of ints.

static inline void int_queue_push
(
    Queue *queue,
    int value
)
{
    queue_push(queue, &value);
}

static inline int int_queue_pop
(
    Queue *queue
)
{
    int value;
    queue_pop(queue, &value);
    return value;
}

#endif
