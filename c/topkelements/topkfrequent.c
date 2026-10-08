#include "common/heap.h"
#include "common/map.h"

// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

typedef struct
{
    int num;
    int frequency;
} Entry;

// min-heap order: the least frequent number comes first
bool entry_frequency_less
(
    const void *a,
    const void *b
)
{
    return ((const Entry *)a)->frequency < ((const Entry *)b)->frequency;
}

// The k numbers are returned in a new array that the caller must free.
int *find_top_k_frequent_numbers
(
    const int *nums,
    int nums_len,
    int k
)
{
    // Find the frequency of each number
    IntMap num_frequency_map = {0};
    for (int i = 0; i < nums_len; i++)
    {
        intmap_add(&num_frequency_map, nums[i], 1);
    }

    // Create a min heap to store entries with frequency
    Heap min_freq_heap = heap_new(sizeof(Entry), entry_frequency_less);

    // Go through all numbers in num_frequency_map and push them into the
    // min heap. If the heap size is more than k, remove the smallest (top)
    // entry
    int iter = 0;
    int num;
    int frequency;
    while (intmap_next(&num_frequency_map, &iter, &num, &frequency))
    {
        heap_push(&min_freq_heap, &(Entry){num, frequency});
        if (min_freq_heap.len > k)
        {
            heap_pop(&min_freq_heap, NULL);
        }
    }

    // Create a list of top k frequent numbers
    int *top_numbers = malloc((size_t)k * sizeof(int));
    for (int i = k - 1; i >= 0; i--)
    {
        Entry entry;
        heap_pop(&min_freq_heap, &entry);
        top_numbers[i] = entry.num;
    }

    heap_free(&min_freq_heap);
    intmap_free(&num_frequency_map);
    return top_numbers;
}
