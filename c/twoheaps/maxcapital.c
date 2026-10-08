#include "common/heap.h"

// Project pairs a project's index with the value its heap is ordered by.
typedef struct
{
    int value;
    int index;
} Project;

// min-heap order: the project needing the least capital comes first
bool project_value_less
(
    const void *a,
    const void *b
)
{
    return ((const Project *)a)->value < ((const Project *)b)->value;
}

// max-heap order: the project with the most profit comes first
bool project_value_greater
(
    const void *a,
    const void *b
)
{
    return ((const Project *)a)->value > ((const Project *)b)->value;
}

int find_maximum_capital
(
    const int *capital_arr,
    const int *profits_arr,
    int n,
    int number_of_projects,
    int initial_capital
)
{
    Heap min_capital_heap = heap_new(sizeof(Project), project_value_less);
    Heap max_profit_heap = heap_new(sizeof(Project), project_value_greater);

    // insert all project indices into the min-capital heap
    for (int i = 0; i < n; i++)
    {
        heap_push(&min_capital_heap, &(Project){capital_arr[i], i});
    }

    // try to find a total of 'number_of_projects' best projects
    int available_capital = initial_capital;
    for (int p = 0; p < number_of_projects; p++)
    {
        // move all affordable projects into the max-profit heap
        while (min_capital_heap.len > 0 &&
               ((Project *)heap_top(&min_capital_heap))->value <=
                   available_capital)
        {
            Project project;
            heap_pop(&min_capital_heap, &project);
            heap_push(&max_profit_heap,
                      &(Project){profits_arr[project.index], project.index});
        }

        // no affordable project found
        if (max_profit_heap.len == 0)
        {
            break;
        }

        // select the project with the maximum profit
        Project best;
        heap_pop(&max_profit_heap, &best);
        available_capital += profits_arr[best.index];
    }

    heap_free(&min_capital_heap);
    heap_free(&max_profit_heap);
    return available_capital;
}
