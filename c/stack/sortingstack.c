#include "common/list.h"

// Given a stack, sort it using only stack operations (push and pop).
// You can use an additional temporary stack,
//
// but you may not copy the elements into any other data structure (such as an
// array).
// The values in the stack are to be sorted in descending order, with the
// largest elements on top.
//
// Example 1. Input: [34, 3, 31, 98, 92, 23]
// Output: [3, 23, 31, 34, 92, 98]
//
// Example 2. Input: [4, 3, 2, 10, 12, 1, 5, 6]
// Output: [1, 2, 3, 4, 5, 6, 10, 12]
//
// Example 3. Input: [20, 10, -5, -1]
// Output: [-5, -1, 10, 20]

// A stack here is an IntList whose last item is the top. The input stack is
// emptied, and the sorted stack is returned for the caller to free.
IntList sort_stack
(
    IntList *input
)
{
    IntList tmp_stack = {0}; // a temporary stack to hold sorted elements

    while (input->len > 0)
    {
        // Pop the top element from the input stack
        int tmp = intlist_pop(input);

        // Compare the element with the top element of the temporary stack
        // and move elements from tmp_stack to input stack until the correct
        // position is found
        while (tmp_stack.len > 0 && tmp_stack.items[tmp_stack.len - 1] > tmp)
        {
            intlist_push(input, intlist_pop(&tmp_stack));
        }

        // Push the current element to the temporary stack in the correct
        // sorted position
        intlist_push(&tmp_stack, tmp);
    }

    return tmp_stack; // Return the sorted stack
}
