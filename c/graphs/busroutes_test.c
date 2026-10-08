#include "busroutes.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *routes;
        int source;
        int target;
        int want;
    } tests[] = {
        {"example 1", "[[1, 2, 7], [3, 6, 7]]", 1, 6, 2},
        {"example 2", "[[7, 12], [4, 5, 15], [6], [15, 19], [9, 12, 13]]", 15,
         12, -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix routes = t_parse_matrix(tt->routes);
        int got = num_buses_to_destination(&routes, tt->source, tt->target);
        t_check_int("num_buses_to_destination()", got, tt->want);
        intmatrix_free(&routes);
    }
    return t_done();
}
