#include "employeefreetime.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // up to three employees; an unused one has no intervals
        Interval *employee[3];
        int employee_len[3];
        int employees;
        const char *want;
    } tests[] = {
        {"Example 1: two employees, one free interval",
         {(Interval[]){{1, 3}, {5, 6}}, (Interval[]){{2, 3}, {6, 8}}},
         {2, 2},
         2,
         "[[3, 5]]"},
        {"Example 2: three employees, two free intervals",
         {(Interval[]){{1, 3}, {9, 12}}, (Interval[]){{2, 4}},
          (Interval[]){{6, 8}}},
         {2, 1, 1},
         3,
         "[[4, 6], [8, 9]]"},
        {"Example 3: three employees, one free interval",
         {(Interval[]){{1, 3}}, (Interval[]){{2, 4}},
          (Interval[]){{3, 5}, {7, 9}}},
         {1, 1, 2},
         3,
         "[[5, 7]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got_len = 0;
        Interval *got =
            find_employee_free_time((const Interval *const *)tt->employee,
                                    tt->employee_len, tt->employees, &got_len);
        t_check_text("find_employee_free_time()",
                     format_intervals(got, got_len), tt->want);
        free(got);
    }
    return t_done();
}
