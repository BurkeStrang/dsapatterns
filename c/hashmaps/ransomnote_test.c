#include "ransomnote.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *ransom_note;
        const char *magazine;
        bool want;
    } tests[] = {
        {"can construct hello from hellworld", "hello", "hellworld", true},
        {"can construct notes from stoned", "notes", "stoned", true},
        {"cannot construct apple from pale", "apple", "pale", false},
        {"exact match", "abc", "abc", true},
        {"not enough letters", "aabb", "ab", false},
        {"empty ransom note", "", "anything", true},
        {"empty magazine", "a", "", false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = can_construct(tt->ransom_note, tt->magazine);
        t_check_bool("can_construct()", got, tt->want);
    }
    return t_done();
}
