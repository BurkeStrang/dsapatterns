#include "common/list.h"
#include "common/map.h"
#include "common/sort.h"

// Given two 2D arrays of item-value pairs, named items1 and items2.
// item[i] = [valuei, weighti],
// where each valuei in these arrays
// is unique within its own array and is paired with a weight i.
// Combine these arrays such that if a value appears in both,
// its weights are summed up.
// The final merged array should be sorted based on the valuei.
//
// Example 1:
// Input: items1 = [[1,2],[4,3]], items2 = [[2,1],[4,3],[3,4]]
// Expected Output: [[1,2],[2,1],[3,4],[4,6]]
// Justification: Item 1 has value 2 in items1 and doesn't exist in items2, item
// 2 has value 1 in items2, item 4 is summed up.
//
// Example 2:
// Input: items1 = [[5,5]], items2 = [[5,10]]
// Expected Output: [[5,15]]
// Justification: Item 5 exists in both arrays, so their values are summed.
//
// Example 3:
// Input: items1 = [[1,1],[2,2]], items2 = [[3,3]]
// Expected Output: [[1,1],[2,2],[3,3]]
// Justification: All items are unique across items1 and items2, so they remain
// unchanged.
// Constraints:
//
// 1 <= items1.length, items2.length <= 1000
// items1[i].length == items2[i].length == 2
// 1 <= valuei, weighti <= 1000
// Each valuei in items1 is unique.
// Each valuei in items2 is unique.

// C has no built-in ordered map, so the weights are summed in a hash map and
// the values are sorted before the result is built.
// The merged items are returned in a matrix that the caller must free.
IntMatrix merge_similar_items
(
    const IntMatrix *items1,
    const IntMatrix *items2
)
{
    IntMap merged_items = {0};

    // Process items from the first array
    for (int i = 0; i < items1->len; i++)
    {
        const IntList *item = &items1->rows[i];
        intmap_add(&merged_items, item->items[0], item->items[1]);
    }

    // Process items from the second array
    for (int i = 0; i < items2->len; i++)
    {
        const IntList *item = &items2->rows[i];
        intmap_add(&merged_items, item->items[0], item->items[1]);
    }

    IntList values = {0};
    int iter = 0;
    int value = 0;
    int weight = 0;
    while (intmap_next(&merged_items, &iter, &value, &weight))
    {
        intlist_push(&values, value);
    }
    sort_ints(values.items, values.len);

    IntMatrix result = {0};
    for (int i = 0; i < values.len; i++)
    {
        IntList item = {0};
        intlist_push(&item, values.items[i]);
        intlist_push(&item, intmap_get(&merged_items, values.items[i]));
        intmatrix_push(&result, item);
    }

    intlist_free(&values);
    intmap_free(&merged_items);
    return result;
}
