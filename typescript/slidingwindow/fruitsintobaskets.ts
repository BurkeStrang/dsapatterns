// You are visiting a farm to collect fruits.
// The farm has a single row of fruit trees.
// You will be given two baskets, and your goal is to pick as many fruits as
// possible to be placed in the given baskets.
//
// You will be given an array of characters where each character represents a
// fruit tree.
// The farm has following restrictions:
//
// Each basket can have only one type of fruit. There is no limit to how many
// fruit a basket can hold.
// You can start with any tree, but you can’t skip a tree once you have started.
// You will pick exactly one fruit from every tree until you cannot, i.e.,
// you will stop when you have to pick from a third fruit type.
// Write a function to return the maximum number of fruits in both baskets.
//
// Example 1:
//
// Input: arr=['A', 'B', 'C', 'A', 'C']
// Output: 3
// Explanation: We can put 2 'C' in one basket and one 'A' in the other from the
// subarray ['C', 'A', 'C']
// Example 2:
//
// Input: arr = ['A', 'B', 'C', 'B', 'B', 'C']
// Output: 5
// Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
// This can be done if we start with the second letter: ['B', 'C', 'B', 'B',
// 'C']
// Constraints:
//
// 1 <= arr.length <=
// 0 <= arr[i] < arr.length

export function maxFruit(arr: string[]): number {
  let windowStart = 0;
  let maxLength = 0;
  const fruitFrequencyMap = new Map<string, number>();
  // try to extend the range [windowStart, windowEnd]
  for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
    const rightFruit = arr[windowEnd];
    fruitFrequencyMap.set(
      rightFruit,
      (fruitFrequencyMap.get(rightFruit) ?? 0) + 1,
    );
    // shrink the sliding window, until we're left with '2' fruits in the
    // frequency map
    while (fruitFrequencyMap.size > 2) {
      const leftFruit = arr[windowStart];
      const count = (fruitFrequencyMap.get(leftFruit) ?? 0) - 1;
      if (count === 0) {
        fruitFrequencyMap.delete(leftFruit);
      } else {
        fruitFrequencyMap.set(leftFruit, count);
      }
      windowStart++; // shrink the window
    }
    maxLength = Math.max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}
