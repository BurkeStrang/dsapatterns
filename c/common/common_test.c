// Tests for the shared building blocks in this folder.
#include "common/heap.h"
#include "common/list.h"
#include "common/map.h"
#include "common/queue.h"
#include "common/strbuf.h"
#include "testing/testing.h"

static void test_intlist(void)
{
    t_run("IntList push, insert, pop, copy");
    IntList list = {0};
    for (int i = 1; i <= 20; i++)
    {
        intlist_push(&list, i);
    }
    intlist_insert(&list, 0, -1);
    intlist_insert(&list, 2, 99);
    t_check_int("len", list.len, 22);
    t_check_int("items[0]", list.items[0], -1);
    t_check_int("items[2]", list.items[2], 99);
    t_check_int("pop", intlist_pop(&list), 20);
    IntList copy = intlist_copy(&list);
    copy.items[0] = 7;
    t_check_int("original after copy change", list.items[0], -1);
    intlist_free(&copy);
    intlist_free(&list);
}

static void test_matrix(void)
{
    t_run("IntMatrix parse, format, sort");
    IntMatrix matrix = t_parse_matrix("[[3, 1], [], [2], [1, 3, -5]]");
    t_check_text("format", t_format_matrix(&matrix),
                 "[[3, 1], [], [2], [1, 3, -5]]");
    t_sort_matrix(&matrix, true);
    t_check_matrix("sorted", &matrix, "[[], [-5, 1, 3], [1, 3], [2]]");
    intmatrix_insert(&matrix, 0, intlist_from((int[]){9}, 1));
    t_check_int("first row", matrix.rows[0].items[0], 9);
    intmatrix_free(&matrix);

    IntList nums = t_parse_ints_with_null("[1, null, -2]", -999);
    t_check_ints("parse ints", nums.items, nums.len, INTS(1, -999, -2));
    intlist_free(&nums);
}

static void test_heap(void)
{
    t_run("Heap orders ints both ways");
    int values[] = {5, 1, 9, 3, 7, 3, 8, 2, 6, 4, 0};
    Heap min_heap = int_min_heap_new();
    Heap max_heap = int_max_heap_new();
    for (int i = 0; i < LEN(values); i++)
    {
        int_heap_push(&min_heap, values[i]);
        int_heap_push(&max_heap, values[i]);
    }
    t_check_int("min top", int_heap_top(&min_heap), 0);
    t_check_int("max top", int_heap_top(&max_heap), 9);
    int previous = -1;
    while (min_heap.len > 0)
    {
        int value = int_heap_pop(&min_heap);
        if (value < previous)
        {
            t_errorf("min heap gave %d after %d", value, previous);
        }
        previous = value;
    }
    // remove from the middle and check the order still holds
    heap_remove(&max_heap, 3, NULL);
    previous = 100;
    int count = 0;
    while (max_heap.len > 0)
    {
        int value = int_heap_pop(&max_heap);
        if (value > previous)
        {
            t_errorf("max heap gave %d after %d", value, previous);
        }
        previous = value;
        count++;
    }
    t_check_int("items left after remove", count, LEN(values) - 1);
    heap_free(&min_heap);
    heap_free(&max_heap);
}

static void test_queue(void)
{
    t_run("Queue is first in, first out");
    Queue queue = queue_new(sizeof(int));
    int next_out = 0;
    for (int i = 0; i < 100; i++)
    {
        int_queue_push(&queue, i);
        if (i % 3 == 0)
        {
            t_check_int("pop", int_queue_pop(&queue), next_out++);
        }
    }
    while (queue.len > 0)
    {
        t_check_int("pop", int_queue_pop(&queue), next_out++);
    }
    t_check_int("total popped", next_out, 100);
    queue_free(&queue);
}

static void test_intmap(void)
{
    t_run("IntMap set, add, remove, iterate");
    IntMap map = {0};
    for (int i = -500; i < 500; i++)
    {
        intmap_set(&map, i, i * 2);
    }
    t_check_int("len", map.len, 1000);
    t_check_int("get", intmap_get(&map, -321), -642);
    t_check_int("missing", intmap_get(&map, 12345), 0);
    for (int i = -500; i < 500; i += 2)
    {
        intmap_remove(&map, i);
    }
    t_check_int("len after remove", map.len, 500);
    t_check_bool("has removed", intmap_has(&map, -500), false);
    t_check_bool("has kept", intmap_has(&map, -499), true);
    t_check_int("add", intmap_add(&map, 7, 1), 15);
    t_check_int("add new", intmap_add(&map, 100000, 1), 1);
    int iter = 0;
    int key;
    int value;
    int seen = 0;
    while (intmap_next(&map, &iter, &key, &value))
    {
        seen++;
    }
    t_check_int("iterated", seen, 501);
    intmap_free(&map);
}

static void test_strmap(void)
{
    t_run("StrMap set, add, remove, iterate");
    StrMap map = {0};
    char key[16];
    for (int i = 0; i < 300; i++)
    {
        snprintf(key, sizeof(key), "key%d", i);
        strmap_set(&map, key, i);
    }
    t_check_int("len", map.len, 300);
    t_check_int("get", strmap_get(&map, "key42"), 42);
    t_check_int("missing", strmap_get(&map, "nope"), 0);
    strmap_remove(&map, "key42");
    t_check_bool("has removed", strmap_has(&map, "key42"), false);
    t_check_int("add", strmap_add(&map, "key1", 5), 6);
    t_check_int("add new", strmap_add(&map, "fresh", 1), 1);
    int iter = 0;
    const char *found;
    int value;
    int seen = 0;
    while (strmap_next(&map, &iter, &found, &value))
    {
        seen++;
    }
    t_check_int("iterated", seen, 300);
    strmap_free(&map);
}

static void test_strbuf(void)
{
    t_run("StrBuf push, append, pop, take");
    StrBuf buf = {0};
    strbuf_push(&buf, 'a');
    strbuf_append(&buf, "bcdefghijklmnopqrstuvwxyz");
    t_check_int("len", buf.len, 26);
    t_check_char("pop", strbuf_pop(&buf), 'z');
    char *text = strbuf_take(&buf);
    t_check_str("take", text, "abcdefghijklmnopqrstuvwxy");
    free(text);
    char *empty = strbuf_take(&buf);
    t_check_str("take empty", empty, "");
    free(empty);
}

int main(void)
{
    test_intlist();
    test_matrix();
    test_heap();
    test_queue();
    test_intmap();
    test_strmap();
    test_strbuf();
    return t_done();
}
