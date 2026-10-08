// Shared types and helpers for the sliding window problems.
#ifndef DSAPATTERNS_SLIDINGWINDOW_SHARED_H
#define DSAPATTERNS_SLIDINGWINDOW_SHARED_H

#include <stdbool.h>
#include <stddef.h>

static inline double abs_double
(
    double x
)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

// equal_doubles reports whether a and b hold the same numbers. A NULL array
// only equals another NULL array.
static inline bool equal_doubles
(
    const double *a,
    int a_len,
    const double *b,
    int b_len
)
{
    if (a == NULL || b == NULL)
    {
        return a == b;
    }
    if (a_len != b_len)
    {
        return false;
    }
    const double eps = 1e-9;
    for (int i = 0; i < a_len; i++)
    {
        if (abs_double(a[i] - b[i]) > eps)
        {
            return false;
        }
    }
    return true;
}

#endif
