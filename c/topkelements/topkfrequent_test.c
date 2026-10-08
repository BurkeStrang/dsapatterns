#include "topkfrequent.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k;
        // every number that is allowed to appear in the answer, since numbers
        // with the same frequency can be picked in any order
        const int *valid;
        int valid_len;
    } tests[] = {
        {"Example 1", INTS(1, 3, 5, 12, 11, 12, 11), 2, INTS(11, 12)},
        {"Example 2", INTS(5, 12, 11, 3, 11), 2, INTS(11, 5, 12, 3)},
        {"Example 3", INTS(1, 1, 1, 3, 3, 3, 5, 5, 5, 12), 2, INTS(1, 3, 5)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_top_k_frequent_numbers(tt->nums, tt->nums_len, tt->k);
        bool ok = got != NULL;
        for (int n = 0; ok && n < tt->k; n++)
        {
            bool found = false;
            for (int v = 0; v < tt->valid_len; v++)
            {
                found = found || got[n] == tt->valid[v];
            }
            ok = found;
        }
        if (!ok)
        {
            t_errorf("find_top_k_frequent_numbers() = %s, want %d of %s",
                     t_format_ints(got, tt->k), tt->k,
                     t_format_ints(tt->valid, tt->valid_len));
        }
        free(got);
    }
    return t_done();
}
