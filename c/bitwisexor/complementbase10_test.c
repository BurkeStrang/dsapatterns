#include "complementbase10.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int num;
        int want;
    } tests[] = {
        // number: 5 (binary 101) -> complement: 2 (binary 010)
        {"Example 1", 5, 2},
        // number: 7 (binary 111) -> complement: 0 (binary 000)
        {"Example 2", 7, 0},
        // number: 10 (binary 1010) -> complement: 5 (binary 0101)
        {"Example 3", 10, 5},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = bitwise_complement(tt->num);
        t_check_int("bitwise_complement()", got, tt->want);
    }
    return t_done();
}
