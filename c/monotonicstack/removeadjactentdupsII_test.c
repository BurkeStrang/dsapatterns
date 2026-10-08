#include "removeadjactentdupsII.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int k;
        const char *want;
    } tests[] = {
        {"remove bbb then aaa", "abbbaaca", 3, "ca"},
        {"no removal possible", "abbaccaa", 3, "abbaccaa"},
        {"remove ccc then aaa", "abbacccaa", 3, "abb"},
        {"all removed", "aaa", 3, ""},
        {"single char, k=2", "a", 2, "a"},
        {"multiple removals", "deeedbbcccbdaa", 3, "aa"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = remove_duplicates_ii(tt->s, tt->k);
        t_check_str("remove_duplicates_ii()", got, tt->want);
        free(got);
    }
    return t_done();
}
