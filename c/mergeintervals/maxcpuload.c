#include "common/heap.h"

#include <stdlib.h>

// We are given a list of Jobs. Each job has a Start time, an End time, and a
// CPU load when it is running. Our goal is to find the maximum CPU load at any
// time if all the jobs are running on the same machine.
//
// Example 1:
// Jobs: [[1,4,3], [2,5,4], [7,9,6]]
// Output: 7
// Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load
// (3+4=7) will be when both the jobs are running at the same time i.e., during
// the time interval (2,4).
//
// Example 2:
// Jobs: [[6,7,10], [2,4,11], [8,12,15]]
// Output: 15
// Explanation: None of the jobs overlap, therefore we will take the maximum
// load of any job which is 15.
//
// Example 3:
// Jobs: [[1,4,2], [2,4,1], [3,6,5]]
// Output: 8
// Explanation: Maximum CPU load will be 8 as all jobs overlap during the time
// interval [3,4].

typedef struct
{
    int start;
    int end;
    int cpu_load;
} Job;

int compare_job_starts
(
    const void *a,
    const void *b
)
{
    const Job *x = a;
    const Job *y = b;
    return (x->start > y->start) - (x->start < y->start);
}

// orders the heap by job end time, earliest first
bool job_ends_first
(
    const void *a,
    const void *b
)
{
    return ((const Job *)a)->end < ((const Job *)b)->end;
}

int find_max_cpu_load
(
    Job *jobs,
    int jobs_len
)
{
    qsort(jobs, (size_t)jobs_len, sizeof(Job), compare_job_starts);

    int max_cpu_load = 0;
    int current_cpu_load = 0;
    Heap min_heap = heap_new(sizeof(Job), job_ends_first);

    for (int i = 0; i < jobs_len; i++)
    {
        Job job = jobs[i];
        // remove all jobs that have ended
        while (min_heap.len > 0 &&
               job.start > ((Job *)heap_top(&min_heap))->end)
        {
            Job ended;
            heap_pop(&min_heap, &ended);
            current_cpu_load -= ended.cpu_load;
        }

        // add the current job into the min_heap
        heap_push(&min_heap, &job);
        current_cpu_load += job.cpu_load;
        if (current_cpu_load > max_cpu_load)
        {
            max_cpu_load = current_cpu_load;
        }
    }
    heap_free(&min_heap);
    return max_cpu_load;
}
