#include "mergesimiliaritems.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *items1;
        const char *items2;
        const char *want;
    } tests[] = {
        {"Example 1", "[[1, 2], [4, 3]]", "[[2, 1], [4, 3], [3, 4]]",
         "[[1, 2], [2, 1], [3, 4], [4, 6]]"},
        {"Example 2", "[[5, 5]]", "[[5, 10]]", "[[5, 15]]"},
        {"Example 3", "[[1, 1], [2, 2]]", "[[3, 3]]",
         "[[1, 1], [2, 2], [3, 3]]"},
        {"Unsorted input", "[[9, 1], [2, 2]]", "[[5, 3], [2, 4]]",
         "[[2, 6], [5, 3], [9, 1]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix items1 = t_parse_matrix(tt->items1);
        IntMatrix items2 = t_parse_matrix(tt->items2);
        IntMatrix got = merge_similar_items(&items1, &items2);
        t_check_matrix("merge_similar_items()", &got, tt->want);
        intmatrix_free(&got);
        intmatrix_free(&items2);
        intmatrix_free(&items1);
    }
    return t_done();
}
