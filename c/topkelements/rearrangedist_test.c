#include "rearrangedist.c"

#include "testing/testing.h"

// valid_rearrangement reports whether output uses exactly the letters of
// input, with every repeat of a letter at least k positions after the
// previous one.
static bool valid_rearrangement
(
    const char *input,
    const char *output,
    int k
)
{
    int counts[256] = {0};
    for (const char *c = input; *c != '\0'; c++)
    {
        counts[(unsigned char)*c]++;
    }
    int last_seen[256];
    for (int i = 0; i < 256; i++)
    {
        last_seen[i] = -1;
    }
    for (int i = 0; output[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)output[i];
        counts[c]--;
        if (last_seen[c] != -1 && i - last_seen[c] < k)
        {
            return false;
        }
        last_seen[c] = i;
    }
    for (int i = 0; i < 256; i++)
    {
        if (counts[i] != 0)
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
        const char *str;
        int k;
        // one valid answer; letters with the same frequency can be picked in
        // any order
        const char *want;
    } tests[] = {
        {"Example 1", "mmpp", 2, "mpmp"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = reorganize_string(tt->str, tt->k);
        if (got == NULL || !valid_rearrangement(tt->str, got, tt->k))
        {
            t_errorf("reorganize_string() = \"%s\", want something like \"%s\"",
                     got == NULL ? "NULL" : got, tt->want);
        }
        free(got);
    }
    return t_done();
}
