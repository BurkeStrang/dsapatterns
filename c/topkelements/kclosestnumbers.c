#include "common/heap.h"
#include "common/list.h"
#include "common/sort.h"

// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

// ClosestEntry is an array index together with how far its number is from X.
typedef struct
{
    int key;
    int value;
} ClosestEntry;

// min-heap order: the smallest difference comes first
bool closest_entry_less
(
    const void *a,
    const void *b
)
{
    return ((const ClosestEntry *)a)->key < ((const ClosestEntry *)b)->key;
}

int binary_search
(
    const int *arr,
    int arr_len,
    int target
)
{
    int low = 0;
    int high = arr_len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > 0)
    {
        return low - 1;
    }
    return low;
}

// The closest numbers are returned in a list that the caller must free.
IntList find_closest_elements
(
    const int *arr,
    int arr_len,
    int k,
    int x
)
{
    int index = binary_search(arr, arr_len, x);
    int low = index - k;
    int high = index + k;
    if (low < 0)
    { // 'low' should not be less than zero
        low = 0;
    }
    if (high > arr_len - 1)
    { // 'high' should not be past the end
        high = arr_len - 1;
    }

    Heap min_heap = heap_new(sizeof(ClosestEntry), closest_entry_less);
    // add all candidate elements to the min heap, sorted by their absolute
    // difference from 'X'
    for (int i = low; i <= high; i++)
    {
        heap_push(&min_heap, &(ClosestEntry){abs(arr[i] - x), i});
    }

    // we need the top 'K' elements having the smallest difference from 'X'
    IntList result = {0};
    for (int n = 0; n < k; n++)
    {
        ClosestEntry entry;
        heap_pop(&min_heap, &entry);
        intlist_push(&result, arr[entry.value]);
    }

    sort_ints(result.items, result.len);
    heap_free(&min_heap);
    return result;
}
