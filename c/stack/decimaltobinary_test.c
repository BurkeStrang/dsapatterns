#include "decimaltobinary.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int num;
        const char *want;
    } tests[] = {
        {"Example 1", 2, "10"},
        {"Example 2", 7, "111"},
        {"Example 3", 18, "10010"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = decimal_to_binary(tt->num);
        t_check_str("decimal_to_binary()", got, tt->want);
        free(got);
    }
    return t_done();
}
