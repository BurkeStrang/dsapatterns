namespace DsaPatterns.OrderedSet;

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
// Justification: Item 1 has value 2 in items1 and doesn't exist in items2, item 2 has value 1 in items2, item 4 is summed up.
//
// Example 2:
// Input: items1 = [[5,5]], items2 = [[5,10]]
// Expected Output: [[5,15]]
// Justification: Item 5 exists in both arrays, so their values are summed.
//
// Example 3:
// Input: items1 = [[1,1],[2,2]], items2 = [[3,3]]
// Expected Output: [[1,1],[2,2],[3,3]]
// Justification: All items are unique across items1 and items2, so they remain unchanged.
// Constraints:
//
// 1 <= items1.length, items2.length <= 1000
// items1[i].length == items2[i].length == 2
// 1 <= valuei, weighti <= 1000
// Each valuei in items1 is unique.
// Each valuei in items2 is unique.

internal static class MergeSimilarItems
{
    internal static IList<IList<int>> Merge(int[][] items1, int[][] items2)
    {
        SortedDictionary<int, int> mergedItems = [];

        // Process items from the first array
        foreach (int[] item in items1)
        {
            if (!mergedItems.ContainsKey(item[0]))
                mergedItems[item[0]] = 0;
            mergedItems[item[0]] += item[1];
        }

        // Process items from the second array
        foreach (int[] item in items2)
        {
            if (!mergedItems.ContainsKey(item[0]))
                mergedItems[item[0]] = 0;
            mergedItems[item[0]] += item[1];
        }

        List<IList<int>> result = [];
        foreach (KeyValuePair<int, int> entry in mergedItems)
        {
            result.Add([entry.Key, mergedItems[entry.Key]]);
        }

        return result;
    }

}
