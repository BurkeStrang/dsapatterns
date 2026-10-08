// Shared types and helpers for the merge intervals problems.
#ifndef DSAPATTERNS_MERGEINTERVALS_SHARED_H
#define DSAPATTERNS_MERGEINTERVALS_SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int start;
    int end;
} Interval;

// INTERVALS writes an Interval array and its length into a test table:
//
//   {"Example 1", INTERVALS({1, 4}, {2, 5}), ...},
#define INTERVALS(...)                                                         \
    (Interval[]){__VA_ARGS__},                                                 \
        (int)(sizeof((Interval[]){__VA_ARGS__}) / sizeof(Interval))
#define NO_INTERVALS NULL, 0

static inline int compare_interval_starts
(
    const void *a,
    const void *b
)
{
    const Interval *x = a;
    const Interval *y = b;
    return (x->start > y->start) - (x->start < y->start);
}

// sort_intervals_by_start sorts the intervals in place by start time.
static inline void sort_intervals_by_start
(
    Interval *intervals,
    int len
)
{
    if (len > 1)
    {
        qsort(intervals, (size_t)len, sizeof(Interval),
              compare_interval_starts);
    }
}

// format_intervals writes intervals as "[[1, 4], [2, 5]]" for comparisons
// and failure messages. It rotates between two buffers, so two results can
// be used in the same message. A NULL array prints as "NULL".
static inline const char *format_intervals
(
    const Interval *intervals,
    int len
)
{
    static char buffers[2][1024];
    static int next = 0;
    if (intervals == NULL && len != 0)
    {
        return "NULL";
    }
    char *buffer = buffers[next];
    next = (next + 1) % 2;
    size_t used = 0;
    used += (size_t)snprintf(buffer + used, sizeof(buffers[0]) - used, "[");
    for (int i = 0; i < len && used < sizeof(buffers[0]) - 32; i++)
    {
        used += (size_t)snprintf(buffer + used, sizeof(buffers[0]) - used,
                                 i == 0 ? "[%d, %d]" : ", [%d, %d]",
                                 intervals[i].start, intervals[i].end);
    }
    snprintf(buffer + used, sizeof(buffers[0]) - used, "]");
    return buffer;
}

#endif
