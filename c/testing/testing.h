// Header-only helpers for table-driven tests.
//
// A test file includes its solution, loops over a table of cases, and reports
// through these helpers:
//
//   t_run(name)         start a test case
//   t_check_int(...)    compare a result with the expected value and report a
//                       failure if they differ (also _bool, _str, _ints, ...)
//   t_errorf(...)       report any other failure for the current case
//   t_done()            print the result; return it from main
#ifndef DSAPATTERNS_TESTING_H
#define DSAPATTERNS_TESTING_H

#include "common/list.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LEN is the number of elements in an array (not a pointer).
#define LEN(array) ((int)(sizeof(array) / sizeof((array)[0])))

// INTS writes an int array and its length into a test table, filling a
// `const int *` field followed by an `int` length field:
//
//   {"basic case", INTS(1, 2, 3), 6},
//
// NO_INTS is the empty array. DOUBLES, CHARS and STRS do the same for other
// element types.
#define INTS(...)                                                              \
    (int[]){__VA_ARGS__}, (int)(sizeof((int[]){__VA_ARGS__}) / sizeof(int))
#define NO_INTS NULL, 0
#define DOUBLES(...)                                                           \
    (double[]){__VA_ARGS__},                                                   \
        (int)(sizeof((double[]){__VA_ARGS__}) / sizeof(double))
#define NO_DOUBLES NULL, 0
#define CHARS(...)                                                             \
    (char[]){__VA_ARGS__}, (int)(sizeof((char[]){__VA_ARGS__}) / sizeof(char))
#define STRS(...)                                                              \
    (const char *[]){__VA_ARGS__},                                             \
        (int)(sizeof((const char *[]){__VA_ARGS__}) / sizeof(const char *))
#define NO_STRS NULL, 0

static const char *t_case_name = "";
static int t_case_count = 0;
static int t_failure_count = 0;
static bool t_case_failed = false;

// t_run starts a new test case; later failures are reported under its name.
static inline void t_run
(
    const char *name
)
{
    t_case_name = name;
    t_case_count++;
    t_case_failed = false;
}

// t_fail_header prints the failing case once and counts it. Use t_errorf.
static inline void t_fail_header
(
    const char *file,
    int line
)
{
    if (!t_case_failed)
    {
        t_case_failed = true;
        t_failure_count++;
    }
    printf("--- FAIL: %s (%s:%d)\n    ", t_case_name, file, line);
}

// t_errorf reports a failure for the current case, like t.Errorf in Go.
#define t_errorf(...)                                                          \
    do                                                                         \
    {                                                                          \
        t_fail_header(__FILE__, __LINE__);                                     \
        printf(__VA_ARGS__);                                                   \
        printf("\n");                                                          \
    } while (0)

// t_done prints the summary and returns the exit code for main.
static inline int t_done(void)
{
    if (t_failure_count > 0)
    {
        printf("FAIL: %d of %d cases failed\n", t_failure_count, t_case_count);
        return 1;
    }
    printf("PASS: %d cases\n", t_case_count);
    return 0;
}

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

// The t_format helpers turn a value into text such as "[1, 2, 3]" for
// failure messages and comparisons. Each call uses one of a few rotating
// buffers, so several results can be used in the same t_errorf. A NULL array
// prints as "NULL".
#define T_FORMAT_BUFFERS 6
#define T_FORMAT_SIZE 4096

static inline char *t_format_buffer(void)
{
    static char buffers[T_FORMAT_BUFFERS][T_FORMAT_SIZE];
    static int next = 0;
    char *buffer = buffers[next];
    next = (next + 1) % T_FORMAT_BUFFERS;
    buffer[0] = '\0';
    return buffer;
}

static inline void t_format_append
(
    char *buffer,
    const char *text
)
{
    size_t used = strlen(buffer);
    snprintf(buffer + used, T_FORMAT_SIZE - used, "%s", text);
}

static inline void t_format_append_ints
(
    char *buffer,
    const int *nums,
    int len
)
{
    char item[32];
    t_format_append(buffer, "[");
    for (int i = 0; i < len; i++)
    {
        snprintf(item, sizeof(item), i == 0 ? "%d" : ", %d", nums[i]);
        t_format_append(buffer, item);
    }
    t_format_append(buffer, "]");
}

static inline const char *t_format_ints
(
    const int *nums,
    int len
)
{
    if (nums == NULL && len != 0)
    {
        return "NULL";
    }
    char *buffer = t_format_buffer();
    t_format_append_ints(buffer, nums, len);
    return buffer;
}

static inline const char *t_format_doubles
(
    const double *nums,
    int len
)
{
    if (nums == NULL && len != 0)
    {
        return "NULL";
    }
    char *buffer = t_format_buffer();
    char item[32];
    t_format_append(buffer, "[");
    for (int i = 0; i < len; i++)
    {
        snprintf(item, sizeof(item), i == 0 ? "%g" : ", %g", nums[i]);
        t_format_append(buffer, item);
    }
    t_format_append(buffer, "]");
    return buffer;
}

static inline const char *t_format_strs
(
    const char *const *strs,
    int len
)
{
    if (strs == NULL && len != 0)
    {
        return "NULL";
    }
    char *buffer = t_format_buffer();
    t_format_append(buffer, "[");
    for (int i = 0; i < len; i++)
    {
        t_format_append(buffer, i == 0 ? "\"" : ", \"");
        t_format_append(buffer, strs[i] == NULL ? "NULL" : strs[i]);
        t_format_append(buffer, "\"");
    }
    t_format_append(buffer, "]");
    return buffer;
}

// t_format_matrix writes a list of lists as "[[1, 2], [3]]".
static inline const char *t_format_matrix
(
    const IntMatrix *matrix
)
{
    char *buffer = t_format_buffer();
    t_format_append(buffer, "[");
    for (int i = 0; i < matrix->len; i++)
    {
        if (i > 0)
        {
            t_format_append(buffer, ", ");
        }
        t_format_append_ints(buffer, matrix->rows[i].items,
                             matrix->rows[i].len);
    }
    t_format_append(buffer, "]");
    return buffer;
}

// ---------------------------------------------------------------------------
// Parsing test data
// ---------------------------------------------------------------------------

// t_parse_ints reads a list such as "[1, 2, null, 4]" into a new IntList.
// A "null" entry is stored as the value of null_value, which lets tree tests
// mark a missing child. The caller frees the list.
static inline IntList t_parse_ints_with_null
(
    const char *text,
    int null_value
)
{
    IntList list = {0};
    const char *p = text;
    while (*p != '\0')
    {
        if (*p == '-' || isdigit((unsigned char)*p))
        {
            char *end;
            intlist_push(&list, (int)strtol(p, &end, 10));
            p = end;
        }
        else if (strncmp(p, "null", 4) == 0)
        {
            intlist_push(&list, null_value);
            p += 4;
        }
        else
        {
            p++;
        }
    }
    return list;
}

static inline IntList t_parse_ints
(
    const char *text
)
{
    return t_parse_ints_with_null(text, 0);
}

// t_parse_matrix reads a list of lists such as "[[1, 2], [3], []]" into a
// new IntMatrix. The caller frees it with intmatrix_free.
static inline IntMatrix t_parse_matrix
(
    const char *text
)
{
    IntMatrix matrix = {0};
    int depth = 0;
    IntList row = {0};
    const char *p = text;
    while (*p != '\0')
    {
        if (*p == '[')
        {
            depth++;
            if (depth == 2)
            {
                row = (IntList){0};
            }
            p++;
        }
        else if (*p == ']')
        {
            if (depth == 2)
            {
                intmatrix_push(&matrix, row);
            }
            depth--;
            p++;
        }
        else if (*p == '-' || isdigit((unsigned char)*p))
        {
            char *end;
            intlist_push(&row, (int)strtol(p, &end, 10));
            p = end;
        }
        else
        {
            p++;
        }
    }
    return matrix;
}

// ---------------------------------------------------------------------------
// Sorting, for results that can come back in any order
// ---------------------------------------------------------------------------

static inline int t_compare_ints
(
    const void *a,
    const void *b
)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

// t_sort_ints sorts an int array in place.
static inline void t_sort_ints
(
    int *nums,
    int len
)
{
    if (len > 1)
    {
        qsort(nums, (size_t)len, sizeof(int), t_compare_ints);
    }
}

static inline int t_compare_rows
(
    const void *a,
    const void *b
)
{
    const IntList *x = a;
    const IntList *y = b;
    for (int i = 0; i < x->len && i < y->len; i++)
    {
        if (x->items[i] != y->items[i])
        {
            return x->items[i] < y->items[i] ? -1 : 1;
        }
    }
    return (x->len > y->len) - (x->len < y->len);
}

// t_sort_matrix sorts the rows of a matrix in place. With sort_within_rows it
// first sorts the numbers inside each row too.
static inline void t_sort_matrix
(
    IntMatrix *matrix,
    bool sort_within_rows
)
{
    if (sort_within_rows)
    {
        for (int i = 0; i < matrix->len; i++)
        {
            t_sort_ints(matrix->rows[i].items, matrix->rows[i].len);
        }
    }
    if (matrix->len > 1)
    {
        qsort(matrix->rows, (size_t)matrix->len, sizeof(matrix->rows[0]),
              t_compare_rows);
    }
}

static inline int t_compare_strs
(
    const void *a,
    const void *b
)
{
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

// t_sort_strs sorts an array of strings in place.
static inline void t_sort_strs
(
    const char **strs,
    int len
)
{
    if (len > 1)
    {
        qsort(strs, (size_t)len, sizeof(strs[0]), t_compare_strs);
    }
}

// ---------------------------------------------------------------------------
// Checks: compare got with want and report a failure if they differ
// ---------------------------------------------------------------------------

static inline void t_check_int_at
(
    const char *file,
    int line,
    const char *label,
    long long got,
    long long want
)
{
    if (got != want)
    {
        t_fail_header(file, line);
        printf("%s = %lld, want %lld\n", label, got, want);
    }
}

static inline void t_check_bool_at
(
    const char *file,
    int line,
    const char *label,
    bool got,
    bool want
)
{
    if (got != want)
    {
        t_fail_header(file, line);
        printf("%s = %s, want %s\n", label, got ? "true" : "false",
               want ? "true" : "false");
    }
}

static inline void t_check_char_at
(
    const char *file,
    int line,
    const char *label,
    char got,
    char want
)
{
    if (got != want)
    {
        t_fail_header(file, line);
        printf("%s = '%c', want '%c'\n", label, got, want);
    }
}

static inline void t_check_str_at
(
    const char *file,
    int line,
    const char *label,
    const char *got,
    const char *want
)
{
    if (got == NULL || strcmp(got, want) != 0)
    {
        t_fail_header(file, line);
        printf("%s = \"%s\", want \"%s\"\n", label, got == NULL ? "NULL" : got,
               want);
    }
}

static inline void t_check_text_at
(
    const char *file,
    int line,
    const char *label,
    const char *got,
    const char *want
)
{
    if (strcmp(got, want) != 0)
    {
        t_fail_header(file, line);
        printf("%s = %s, want %s\n", label, got, want);
    }
}

static inline bool t_equal_ints
(
    const int *a,
    int a_len,
    const int *b,
    int b_len
)
{
    if (a_len != b_len || (a == NULL && a_len != 0))
    {
        return false;
    }
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

static inline void t_check_ints_at
(
    const char *file,
    int line,
    const char *label,
    const int *got,
    int got_len,
    const int *want,
    int want_len
)
{
    if (!t_equal_ints(got, got_len, want, want_len))
    {
        t_fail_header(file, line);
        printf("%s = %s, want %s\n", label, t_format_ints(got, got_len),
               t_format_ints(want, want_len));
    }
}

static inline void t_check_matrix_at
(
    const char *file,
    int line,
    const char *label,
    const IntMatrix *got,
    const char *want_text
)
{
    IntMatrix want = t_parse_matrix(want_text);
    t_check_text_at(file, line, label, t_format_matrix(got),
                    t_format_matrix(&want));
    intmatrix_free(&want);
}

// t_check_int(label, got, want) compares two whole numbers of any size.
#define t_check_int(...) t_check_int_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_bool(label, got, want) compares two booleans.
#define t_check_bool(...) t_check_bool_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_char(label, got, want) compares two characters.
#define t_check_char(...) t_check_char_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_str(label, got, want) compares two strings; a NULL result never
// matches.
#define t_check_str(...) t_check_str_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_text(label, got, want) compares two formatted values, such as the
// output of t_format_matrix, and reports them without extra quotes.
#define t_check_text(...) t_check_text_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_ints(label, got, got_len, want, want_len) compares two int arrays,
// in order. INTS(...) can supply the last two arguments.
#define t_check_ints(...) t_check_ints_at(__FILE__, __LINE__, __VA_ARGS__)

// t_check_matrix(label, &got, "[[1, 2], [3]]") compares a list of lists with
// the expected value written as text.
#define t_check_matrix(...) t_check_matrix_at(__FILE__, __LINE__, __VA_ARGS__)

#endif
