#include "common/heap.h"
#include "common/list.h"
#include "common/map.h"

// You are given a list of tasks that need to be run, in any order, on a server.
// Each task will take one CPU interval to execute but once a task has finished,
// it has a cooling period during which it can’t be run again.
// If the cooling period for all tasks is ‘K’ intervals,
// find the minimum number of CPU intervals that the server needs to finish all
// tasks.
// If at any time the server can’t execute any task then it must stay idle.
//
// Example 1:
// Input: [a, a, a, b, c, c], K=2
// Output: 7
// Explanation: a -> c -> b -> a -> c -> idle -> a
//
// Example 2:
// Input: [a, b, a], K=3
// Output: 5
// Explanation: a -> b -> idle -> idle -> a

int schedule_tasks
(
    const char *const *tasks,
    int tasks_len,
    int k
)
{
    int interval_count = 0;
    StrMap task_frequency_map = {0};
    for (int i = 0; i < tasks_len; i++)
    {
        strmap_add(&task_frequency_map, tasks[i], 1);
    }

    // max heap of how many times each task still has to run; which task a
    // count belongs to doesn't matter for counting intervals
    Heap max_heap = int_max_heap_new();
    int iter = 0;
    const char *task;
    int frequency;
    while (strmap_next(&task_frequency_map, &iter, &task, &frequency))
    {
        int_heap_push(&max_heap, frequency);
    }

    while (max_heap.len > 0)
    {
        IntList wait_list = {0};
        int n = k + 1;
        while (n > 0 && max_heap.len > 0)
        {
            interval_count++;
            int remaining = int_heap_pop(&max_heap);
            if (remaining > 1)
            {
                intlist_push(&wait_list, remaining - 1);
            }
            n--;
        }

        for (int i = 0; i < wait_list.len; i++)
        {
            int_heap_push(&max_heap, wait_list.items[i]);
        }
        intlist_free(&wait_list);

        if (max_heap.len > 0)
        {
            interval_count += n;
        }
    }

    heap_free(&max_heap);
    strmap_free(&task_frequency_map);
    return interval_count;
}
