#include "common/heap.h"
#include "mergeintervals/shared.h"

// For ‘K’ employees, we are given a list of intervals representing each
// employee’s working hours.
// Our goal is to determine if there is a free interval which is common to all
// employees.
//
// Example 1:
// Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
// Output: [3,5]
// Explanation: All the employees are free between [3,5].
//
// Example 2:
// Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
// Output: [4,6], [8,9]
// Explanation: All employees are free between [4,6] and [8,9].
//
// Example 3:
// Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
// Output: [5,7]
// Explanation: All employees are free between [5,7].

typedef struct
{
    Interval interval;
    int employee_index;
    int interval_index;
} EmployeeInterval;

// orders the heap by interval start time, earliest first
bool employee_interval_less
(
    const void *a,
    const void *b
)
{
    const EmployeeInterval *x = a;
    const EmployeeInterval *y = b;
    return x->interval.start < y->interval.start;
}

// schedule[i] holds the schedule_lens[i] working intervals of employee i.
// The free intervals are returned in a new array that the caller must free,
// and its length is stored in result_len.
Interval *find_employee_free_time
(
    const Interval *const *schedule,
    const int *schedule_lens,
    int employees,
    int *result_len
)
{
    Interval *result = NULL;
    int result_cap = 0;
    *result_len = 0;
    Heap min_heap = heap_new(sizeof(EmployeeInterval), employee_interval_less);

    // insert the first interval of each employee to the queue
    for (int i = 0; i < employees; i++)
    {
        EmployeeInterval first = {schedule[i][0], i, 0};
        heap_push(&min_heap, &first);
    }

    Interval previous_interval =
        ((EmployeeInterval *)heap_top(&min_heap))->interval;
    while (min_heap.len > 0)
    {
        EmployeeInterval queue_top;
        heap_pop(&min_heap, &queue_top);
        // if previous_interval is not overlapping with the next interval,
        // insert a free interval
        if (previous_interval.end < queue_top.interval.start)
        {
            if (*result_len == result_cap)
            {
                result_cap = result_cap == 0 ? 4 : result_cap * 2;
                result = realloc(result, (size_t)result_cap * sizeof(Interval));
            }
            result[(*result_len)++] =
                (Interval){previous_interval.end, queue_top.interval.start};
            previous_interval = queue_top.interval;
        }
        else if (previous_interval.end < queue_top.interval.end)
        {
            // overlapping intervals, update the previous_interval if needed
            previous_interval = queue_top.interval;
        }

        // if there are more intervals available for the same employee, add
        // their next interval
        const Interval *employee_schedule = schedule[queue_top.employee_index];
        int next_index = queue_top.interval_index + 1;
        if (schedule_lens[queue_top.employee_index] > next_index)
        {
            EmployeeInterval next = {employee_schedule[next_index],
                                     queue_top.employee_index, next_index};
            heap_push(&min_heap, &next);
        }
    }

    heap_free(&min_heap);
    return result;
}
