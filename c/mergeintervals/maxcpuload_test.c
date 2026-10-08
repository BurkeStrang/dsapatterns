#include "maxcpuload.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Job jobs[3];
        int jobs_len;
        int want;
    } tests[] = {
        {"Example 1: overlapping jobs",
         {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}},
         3,
         7},
        {"Example 2: non-overlapping jobs",
         {{6, 7, 10}, {2, 4, 11}, {8, 12, 15}},
         3,
         15},
        {"Example 3: all overlap", {{1, 4, 2}, {2, 4, 1}, {3, 6, 5}}, 3, 8},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        Job jobs[3];
        memcpy(jobs, tt->jobs, sizeof(jobs)); // the function sorts its input
        int got = find_max_cpu_load(jobs, tt->jobs_len);
        t_check_int("find_max_cpu_load()", got, tt->want);
    }
    return t_done();
}
