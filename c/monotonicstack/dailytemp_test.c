#include "dailytemp.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *temperatures;
        int temperatures_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(70, 73, 75, 71, 69, 72, 76, 73),
         INTS(1, 1, 4, 2, 1, 1, 0, 0)},
        {"Example 2", INTS(73, 72, 71, 70), INTS(0, 0, 0, 0)},
        {"Example 3", INTS(70, 71, 72, 73), INTS(1, 1, 1, 0)},
        {"All same", INTS(60, 60, 60), INTS(0, 0, 0)},
        {"Single element", INTS(80), INTS(0)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = daily_temperatures(tt->temperatures, tt->temperatures_len);
        t_check_ints("daily_temperatures()", got, tt->temperatures_len,
                     tt->want, tt->want_len);
        free(got);
    }
    return t_done();
}
