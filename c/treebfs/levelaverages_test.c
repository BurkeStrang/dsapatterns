#include "levelaverages.c"

#include "testing/testing.h"

static bool equal_doubles
(
    const double *a,
    int a_len,
    const double *b,
    int b_len
)
{
    if (a_len != b_len)
    {
        return false;
    }
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] - b[i] > 1e-9 || b[i] - a[i] > 1e-9)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const double *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", DOUBLES(1, 2.5, 5.5)},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5]", DOUBLES(12, 4, 8)},
        {"Empty tree", "[]", NO_DOUBLES},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got_len = 0;
        double *got = level_average(root, &got_len);
        if (!equal_doubles(got, got_len, tt->want, tt->want_len))
        {
            t_errorf("level_average() = %s, want %s",
                     t_format_doubles(got, got_len),
                     t_format_doubles(tt->want, tt->want_len));
        }
        free(got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
