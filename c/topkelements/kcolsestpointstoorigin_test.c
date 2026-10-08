#include "kcolsestpointstoorigin.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // points and expected points are written as [x, y] pairs
        const char *points;
        int k;
        const char *want;
    } tests[] = {
        {"Example 1", "[[1, 2], [1, 3]]", 1, "[[1, 2]]"},
        {"Example 2", "[[1, 3], [3, 4], [2, -1]]", 2, "[[1, 3], [2, -1]]"},
        {"Example 3", "[[1, 2], [3, 4], [1, -1]]", 2, "[[1, -1], [1, 2]]"},
        {"Example 4", "[[3, 3], [5, -1], [-2, 4]]", 2, "[[3, 3], [-2, 4]]"},
        {"All points are the same", "[[1, 1], [1, 1], [1, 1]]", 2,
         "[[1, 1], [1, 1]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix pairs = t_parse_matrix(tt->points);
        Point *points = malloc((size_t)pairs.len * sizeof(Point));
        for (int p = 0; p < pairs.len; p++)
        {
            points[p] = (Point){pairs.rows[p].items[0], pairs.rows[p].items[1]};
        }
        Point *got = find_closest_points(points, pairs.len, tt->k);
        // the points can come back in any order
        IntMatrix got_pairs = {0};
        for (int p = 0; got != NULL && p < tt->k; p++)
        {
            int pair[] = {got[p].x, got[p].y};
            intmatrix_push(&got_pairs, intlist_from(pair, 2));
        }
        IntMatrix want = t_parse_matrix(tt->want);
        t_sort_matrix(&got_pairs, false);
        t_sort_matrix(&want, false);
        t_check_text("find_closest_points()", t_format_matrix(&got_pairs),
                     t_format_matrix(&want));
        intmatrix_free(&want);
        intmatrix_free(&got_pairs);
        free(got);
        free(points);
        intmatrix_free(&pairs);
    }
    return t_done();
}
