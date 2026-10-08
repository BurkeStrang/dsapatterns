#include "common/list.h"
#include "common/queue.h"

// The permutations are returned in a matrix that the caller must free.
IntMatrix find_permutations
(
    const int *nums,
    int nums_len
)
{
    IntMatrix result = {0};
    Queue permutations = queue_new(sizeof(IntList));
    queue_push(&permutations, &(IntList){0});
    for (int c = 0; c < nums_len; c++)
    {
        int current_number = nums[c];
        // we will take all existing permutations and add the current number
        // to create new permutations
        int n = permutations.len;
        for (int p = 0; p < n; p++)
        {
            IntList old_permutation;
            queue_pop(&permutations, &old_permutation);
            // create a new permutation by adding the current number at every
            // position
            for (int j = 0; j <= old_permutation.len; j++)
            {
                IntList new_permutation = intlist_copy(&old_permutation);
                intlist_insert(&new_permutation, j, current_number);
                if (new_permutation.len == nums_len)
                {
                    intmatrix_push(&result, new_permutation);
                }
                else
                {
                    queue_push(&permutations, &new_permutation);
                }
            }
            intlist_free(&old_permutation);
        }
    }
    // only the empty starting permutation can be left, when nums is empty
    while (permutations.len > 0)
    {
        IntList leftover;
        queue_pop(&permutations, &leftover);
        intlist_free(&leftover);
    }
    queue_free(&permutations);
    return result;
}
