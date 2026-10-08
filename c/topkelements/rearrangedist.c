#include "common/heap.h"
#include "common/list.h"
#include "common/queue.h"
#include "common/strbuf.h"

// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at
// least ‘K’ distance apart from each other.
//
// Example 1:
// Input: "mmpp", K=2
// Output: "mpmp" or "pmpm"
// Explanation: All same characters are 2 distance apart.
//
// Example 2:
// Input: "Programming", K=3
// Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
// Explanation: All same characters are 3 distance apart.
//
// Example 3:
// Input: "aab", K=2
// Output: "aba"
// Explanation: All same characters are 2 distance apart.
//
// Example 4:
// Input: "aappa", K=3
// Output: ""
// Explanation: We cannot find an arrangement of the string where any two 'a'
// are 3 distance apart.

typedef struct
{
    char letter;
    int frequency;
} CharFreq;

// max-heap order: the most frequent letter comes first
bool char_freq_greater
(
    const void *a,
    const void *b
)
{
    return ((const CharFreq *)a)->frequency > ((const CharFreq *)b)->frequency;
}

// The result is a new string that the caller must free; it is empty when the
// letters can't be rearranged.
char *reorganize_string
(
    const char *str,
    int k
)
{
    if (k <= 1)
    {
        return str_copy(str);
    }

    int char_frequency[256] = {0};
    for (const char *chr = str; *chr != '\0'; chr++)
    {
        char_frequency[(unsigned char)*chr]++;
    }

    Heap max_heap = heap_new(sizeof(CharFreq), char_freq_greater);
    for (int chr = 0; chr < 256; chr++)
    {
        if (char_frequency[chr] > 0)
        {
            heap_push(&max_heap, &(CharFreq){(char)chr, char_frequency[chr]});
        }
    }

    StrBuf result_builder = {0};
    Queue queue = queue_new(sizeof(CharFreq));

    while (max_heap.len > 0)
    {
        CharFreq current_entry;
        heap_pop(&max_heap, &current_entry);
        strbuf_push(&result_builder, current_entry.letter);
        current_entry.frequency--;
        queue_push(&queue, &current_entry);

        if (queue.len == k)
        {
            CharFreq entry;
            queue_pop(&queue, &entry);
            if (entry.frequency > 0)
            {
                heap_push(&max_heap, &entry);
            }
        }
    }

    queue_free(&queue);
    heap_free(&max_heap);

    if (result_builder.len == (int)strlen(str))
    {
        return strbuf_take(&result_builder);
    }
    strbuf_free(&result_builder);
    return str_copy("");
}
