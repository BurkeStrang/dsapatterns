#include "taskscheduelall.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int tasks;
        const char *prerequisites;
        // every valid ordering, sorted; they can come back in any order
        const char *want;
    } tests[] = {
        {"Example 1: two orderings", 4, "[[3, 2], [3, 0], [2, 0], [2, 1]]",
         "[[3, 2, 0, 1], [3, 2, 1, 0]]"},
        {"Example 2: one ordering", 3, "[[0, 1], [1, 2]]", "[[0, 1, 2]]"},
        {"Example 3: thirteen orderings", 6,
         "[[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]]",
         "[[0, 1, 3, 2, 4, 5], [0, 1, 3, 2, 5, 4], [0, 1, 3, 4, 2, 5],"
         " [0, 1, 4, 3, 2, 5], [1, 0, 3, 2, 4, 5], [1, 0, 3, 2, 5, 4],"
         " [1, 0, 3, 4, 2, 5], [1, 0, 4, 3, 2, 5], [1, 3, 0, 2, 4, 5],"
         " [1, 3, 0, 2, 5, 4], [1, 3, 0, 4, 2, 5], [1, 3, 2, 0, 4, 5],"
         " [1, 3, 2, 0, 5, 4]]"},
        {"No prerequisites: every arrangement", 3, "[]",
         "[[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]]"},
        {"Cyclic prerequisites: no ordering", 3, "[[0, 1], [1, 2], [2, 0]]",
         "[]"},
        {"No tasks", 0, "[]", "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix prerequisites = t_parse_matrix(tt->prerequisites);
        IntMatrix got = print_orders(tt->tasks, &prerequisites);
        t_sort_matrix(&got, false);
        t_check_matrix("print_orders()", &got, tt->want);
        intmatrix_free(&got);
        intmatrix_free(&prerequisites);
    }
    return t_done();
}
