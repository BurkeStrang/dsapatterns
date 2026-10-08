#include "removeadjacentdups.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        const char *want;
    } tests[] = {
        {"empty string", "", ""},
        {"no duplicates", "abcd", "abcd"},
        {"all removed", "abccba", ""},
        {"simple pair", "aabb", ""},
        {"single removal", "foobar", "fbar"},
        {"triple duplicate", "fooobar", "fobar"},
        {"nested removals", "azxxzy", "ay"},
        {"single char", "a", "a"},
        {"all same", "aaaa", ""},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = remove_duplicates(tt->s);
        t_check_str("remove_duplicates()", got, tt->want);
        free(got);
    }
    return t_done();
}
