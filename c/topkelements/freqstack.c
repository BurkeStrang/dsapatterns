#include "common/heap.h"
#include "common/map.h"

// Design a class that simulates a Stack data structure,
// implementing the following two operations:
//
// push(int num): Pushes the number ‘num’ on the stack.
// pop(): Returns the most frequent number in the stack.
// If there is a tie, return the number which was pushed later.
//
// Example:
// After following push operations: push(1), push(2), push(3), push(2), push(1),
// push(2), push(5)
// 1. pop() should return 2, as it is the most frequent number
// 2. Next pop() should return 1
// 3. Next pop() should return 2

typedef struct
{
    int number;
    int frequency;
    int sequence_number;
} Element;

// max-heap order: the most frequent number comes first, and for a tie the
// one pushed most recently
bool element_comes_first
(
    const void *a,
    const void *b
)
{
    const Element *x = a;
    const Element *y = b;
    return x->frequency > y->frequency ||
           (x->frequency == y->frequency &&
            x->sequence_number > y->sequence_number);
}

typedef struct
{
    int sequence_number;
    Heap max_heap;
    IntMap frequency_map;
} FreqStack;

FreqStack freq_stack_new(void)
{
    FreqStack stack = {0};
    stack.max_heap = heap_new(sizeof(Element), element_comes_first);
    return stack;
}

void freq_stack_free
(
    FreqStack *stack
)
{
    heap_free(&stack->max_heap);
    intmap_free(&stack->frequency_map);
}

void freq_stack_push
(
    FreqStack *stack,
    int num
)
{
    int frequency = intmap_add(&stack->frequency_map, num, 1);
    heap_push(&stack->max_heap,
              &(Element){num, frequency, stack->sequence_number});
    stack->sequence_number++;
}

int freq_stack_pop
(
    FreqStack *stack
)
{
    Element top;
    heap_pop(&stack->max_heap, &top);
    int num = top.number;

    if (intmap_get(&stack->frequency_map, num) > 1)
    {
        intmap_add(&stack->frequency_map, num, -1);
    }
    else
    {
        intmap_remove(&stack->frequency_map, num);
    }

    return num;
}
