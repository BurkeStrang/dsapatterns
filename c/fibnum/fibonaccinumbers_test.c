#include "fibonaccinumbers.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        long long want;
    } tests[] = {
        {"Example 1", 0, 0}, {"Example 2", 1, 1},
        {"Example 3", 2, 1}, {"Example 4", 3, 2},
        {"Example 5", 4, 3}, {"Example 6", 55, 139583862445},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        long long got = calculate_fibonacci(tt->n);
        t_check_int("calculate_fibonacci()", got, tt->want);
    }
    return t_done();
}
