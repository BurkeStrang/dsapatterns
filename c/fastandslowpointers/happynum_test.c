#include "happynum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int num;
        bool want;
    } tests[] = {
        {"Happy number 19", 19, true},
        {"Happy number 1", 1, true},
        {"Unhappy number 2", 2, false},
        {"Unhappy number 4", 4, false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = is_happy(tt->num);
        t_check_bool("is_happy()", got, tt->want);
    }
    return t_done();
}
