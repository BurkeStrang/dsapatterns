namespace DsaPatterns.SlidingWindow;

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
// Explanation: We can put 2 'C' in one basket and one 'A' in the other from
// the subarray ['C', 'A', 'C']
// Example 2:
//
// Input: arr = ['A', 'B', 'C', 'B', 'B', 'C']
// Output: 5
// Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
// This can be done if we start with the second letter:
// ['B', 'C', 'B', 'B', 'C']
// Constraints:
//
// 1 <= arr.length <=
// 0 <= arr[i] < arr.length

internal static class FruitsIntoBaskets
{
    internal static int MaxFruit(char[] arr)
    {
        int windowStart = 0;
        int maxLength = 0;
        Dictionary<char, int> fruitFrequencyMap = [];
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < arr.Length; windowEnd++)
        {
            char rightFruit = arr[windowEnd];
            fruitFrequencyMap[rightFruit] =
                fruitFrequencyMap.GetValueOrDefault(rightFruit) + 1;
            // shrink the sliding window, until we're left with '2' fruits in
            // the frequency map
            while (fruitFrequencyMap.Count > 2)
            {
                char leftFruit = arr[windowStart];
                fruitFrequencyMap[leftFruit]--;
                if (fruitFrequencyMap[leftFruit] == 0)
                {
                    fruitFrequencyMap.Remove(leftFruit);
                }

                windowStart++; // shrink the window
            }

            maxLength = Math.Max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
}
