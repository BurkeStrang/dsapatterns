#include "scheduelingtask.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *const *tasks;
        int tasks_len;
        int k;
        int want;
    } tests[] = {
        {"Example 1", STRS("a", "a", "a", "b", "c", "c"), 2, 7},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = schedule_tasks(tt->tasks, tt->tasks_len, tt->k);
        t_check_int("schedule_tasks()", got, tt->want);
    }
    return t_done();
}
