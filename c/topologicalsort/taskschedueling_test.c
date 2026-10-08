#include "taskschedueling.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int tasks;
        const char *prerequisites;
        bool want;
    } tests[] = {
        {"Test Case 1", 3, "[[0, 1], [1, 2]]", true},
        {"Test Case 2", 3, "[[0, 1], [1, 2], [2, 0]]", false},
        {"Test Case 3", 4, "[[0, 1], [1, 2], [2, 3]]", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix prerequisites = t_parse_matrix(tt->prerequisites);
        bool got = is_scheduling_possible(tt->tasks, &prerequisites);
        t_check_bool("is_scheduling_possible()", got, tt->want);
        intmatrix_free(&prerequisites);
    }
    return t_done();
}
