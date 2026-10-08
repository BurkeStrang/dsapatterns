// Sorting helpers, used where Go would call sort.Ints.
#ifndef DSAPATTERNS_COMMON_SORT_H
#define DSAPATTERNS_COMMON_SORT_H

#include <stdlib.h>

static inline int compare_ints
(
    const void *a,
    const void *b
)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

// sort_ints sorts an int array in place, smallest first.
static inline void sort_ints
(
    int *nums,
    int len
)
{
    if (len > 1)
    {
        qsort(nums, (size_t)len, sizeof(int), compare_ints);
    }
}

#endif
