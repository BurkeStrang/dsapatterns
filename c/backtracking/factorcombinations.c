#include "common/list.h"

#include <math.h>

// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

void get_all_factors
(
    int n,
    int start,
    IntList *curr,
    IntMatrix *result
)
{
    for (int i = start; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            intlist_push(curr, i);
            IntList curr_copy = intlist_copy(curr);
            intlist_push(&curr_copy, n / i);
            intmatrix_push(result, curr_copy);
            get_all_factors(n / i, i, curr, result);
            intlist_pop(curr);
        }
    }
}

// The combinations are returned in a matrix that the caller must free.
IntMatrix get_factors
(
    int n
)
{
    IntMatrix result = {0};
    IntList curr = {0};
    get_all_factors(n, 2, &curr, &result);
    intlist_free(&curr);
    return result;
}
