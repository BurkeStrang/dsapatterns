#include "simplifypath.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *path;
        const char *want;
    } tests[] = {
        {"Example 1", "/a//b////c/d//././/..", "/a/b/c"},
        {"Example 2", "/../", "/"},
        {"Example 3", "/home//foo/", "/home/foo"},
        {"Root only", "/", "/"},
        {"Multiple .. at root", "/../../..", "/"},
        {"Dot only", "/./././.", "/"},
        {"Trailing slash", "/a/b/c/", "/a/b/c"},
        {"Complex", "/a/./b/../../c/", "/c"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = simplify_path(tt->path);
        t_check_str("simplify_path()", got, tt->want);
        free(got);
    }
    return t_done();
}
