#include "reconstructsequence.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *original_seq;
        int original_len;
        const char *sequences;
        bool want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3, 4), "[[1, 2], [2, 3], [3, 4]]", true},
        {"Example 2", INTS(1, 2, 3, 4), "[[1, 2], [2, 3], [2, 4]]", false},
        {"Example 3", INTS(3, 1, 4, 2, 5), "[[3, 1, 5], [1, 4, 2, 5]]", true},
        {"Different order", INTS(1, 2, 3), "[[3, 2], [2, 1]]", false},
        {"Missing number", INTS(1, 2, 3), "[[1, 2]]", false},
        {"Cyclic sequences", INTS(1, 2, 3), "[[1, 2], [2, 3], [3, 1]]", false},
        {"Number out of range", INTS(1, 2, 3), "[[1, 2], [2, 3], [3, 9]]",
         false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix sequences = t_parse_matrix(tt->sequences);
        bool got =
            can_construct(tt->original_seq, tt->original_len, &sequences);
        t_check_bool("can_construct()", got, tt->want);
        intmatrix_free(&sequences);
    }
    return t_done();
}
