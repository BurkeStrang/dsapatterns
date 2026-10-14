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

export function mergeSimilarItems(
  items1: [number, number][],
  items2: [number, number][],
): number[][] {
  // JavaScript has no ordered map, so the weights are added up in a Map and
  // the values are sorted at the end
  const mergedItems = new Map<number, number>();

  // Process items from the first array
  for (const [value, weight] of items1) {
    mergedItems.set(value, (mergedItems.get(value) ?? 0) + weight);
  }

  // Process items from the second array
  for (const [value, weight] of items2) {
    mergedItems.set(value, (mergedItems.get(value) ?? 0) + weight);
  }

  return [...mergedItems].sort((a, b) => a[0] - b[0]);
}
