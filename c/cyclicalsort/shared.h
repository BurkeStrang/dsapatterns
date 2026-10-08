// Shared helpers for the cyclic sort problems.
#ifndef DSAPATTERNS_CYCLICALSORT_SHARED_H
#define DSAPATTERNS_CYCLICALSORT_SHARED_H

// swap swaps two elements in the array at positions i and j.
static inline void swap
(
    int *arr,
    int i,
    int j
)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

#endif
