#include "comparingstringsbackslash.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str1;
        const char *str2;
        bool want;
    } tests[] = {
        {"Example 1", "xy#z", "xzz#", true},
        {"Example 2", "xy#z", "xyz#", false},
        {"Example 3", "xp#", "xyz##", true},
        {"Example 4", "xywrrmp", "xywrrmu#p", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = compare(tt->str1, tt->str2);
        t_check_bool("compare()", got, tt->want);
    }
    return t_done();
}
