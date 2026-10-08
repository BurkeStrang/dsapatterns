// Growable lists, used where Go would use a slice that is appended to.
#ifndef DSAPATTERNS_COMMON_LIST_H
#define DSAPATTERNS_COMMON_LIST_H

#include <stdlib.h>
#include <string.h>

// IntList is a growable array of ints. A zeroed IntList is an empty list.
typedef struct
{
    int *items;
    int len;
    int cap;
} IntList;

static inline void intlist_reserve
(
    IntList *list,
    int cap
)
{
    if (cap > list->cap)
    {
        list->cap = cap < 8 ? 8 : cap;
        list->items =
            realloc(list->items, (size_t)list->cap * sizeof(list->items[0]));
    }
}

// intlist_push appends value to the end of the list.
static inline void intlist_push
(
    IntList *list,
    int value
)
{
    if (list->len == list->cap)
    {
        intlist_reserve(list, list->cap == 0 ? 8 : list->cap * 2);
    }
    list->items[list->len++] = value;
}

// intlist_pop removes and returns the last value.
static inline int intlist_pop
(
    IntList *list
)
{
    return list->items[--list->len];
}

// intlist_insert puts value at index, moving later values up by one.
static inline void intlist_insert
(
    IntList *list,
    int index,
    int value
)
{
    intlist_push(list, value);
    for (int i = list->len - 1; i > index; i--)
    {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = value;
}

// intlist_from makes a list holding a copy of the given values.
static inline IntList intlist_from
(
    const int *values,
    int len
)
{
    IntList list = {0};
    intlist_reserve(&list, len);
    for (int i = 0; i < len; i++)
    {
        list.items[list.len++] = values[i];
    }
    return list;
}

// intlist_copy makes an independent copy of a list.
static inline IntList intlist_copy
(
    const IntList *list
)
{
    return intlist_from(list->items, list->len);
}

static inline void intlist_free
(
    IntList *list
)
{
    free(list->items);
    *list = (IntList){0};
}

// IntMatrix is a growable list of IntLists, used for results such as
// [[1, 2], [3]]. A zeroed IntMatrix is empty.
typedef struct
{
    IntList *rows;
    int len;
    int cap;
} IntMatrix;

// intmatrix_push appends row. The matrix takes ownership of the row.
static inline void intmatrix_push
(
    IntMatrix *matrix,
    IntList row
)
{
    if (matrix->len == matrix->cap)
    {
        matrix->cap = matrix->cap < 8 ? 8 : matrix->cap * 2;
        matrix->rows = realloc(matrix->rows,
                               (size_t)matrix->cap * sizeof(matrix->rows[0]));
    }
    matrix->rows[matrix->len++] = row;
}

// intmatrix_insert puts row at index, moving later rows up by one.
static inline void intmatrix_insert
(
    IntMatrix *matrix,
    int index,
    IntList row
)
{
    intmatrix_push(matrix, row);
    for (int i = matrix->len - 1; i > index; i--)
    {
        matrix->rows[i] = matrix->rows[i - 1];
    }
    matrix->rows[index] = row;
}

static inline void intmatrix_free
(
    IntMatrix *matrix
)
{
    for (int i = 0; i < matrix->len; i++)
    {
        intlist_free(&matrix->rows[i]);
    }
    free(matrix->rows);
    *matrix = (IntMatrix){0};
}

// StrList is a growable list of strings. It owns a copy of every string.
typedef struct
{
    char **items;
    int len;
    int cap;
} StrList;

// str_copy returns a newly allocated copy of text.
static inline char *str_copy
(
    const char *text
)
{
    size_t size = strlen(text) + 1;
    char *copy = malloc(size);
    memcpy(copy, text, size);
    return copy;
}

// strlist_push appends a copy of text.
static inline void strlist_push
(
    StrList *list,
    const char *text
)
{
    if (list->len == list->cap)
    {
        list->cap = list->cap < 8 ? 8 : list->cap * 2;
        list->items =
            realloc(list->items, (size_t)list->cap * sizeof(list->items[0]));
    }
    list->items[list->len++] = str_copy(text);
}

static inline void strlist_free
(
    StrList *list
)
{
    for (int i = 0; i < list->len; i++)
    {
        free(list->items[i]);
    }
    free(list->items);
    *list = (StrList){0};
}

#endif
