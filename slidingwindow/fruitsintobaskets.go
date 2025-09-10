package slidingwindow

// You are visiting a farm to collect fruits.
// The farm has a single row of fruit trees.
// You will be given two baskets, and your goal is to pick as many fruits as possible to be placed in the given baskets.
//
// You will be given an array of characters where each character represents a fruit tree.
// The farm has following restrictions:
//
// Each basket can have only one type of fruit. There is no limit to how many fruit a basket can hold.
// You can start with any tree, but you can’t skip a tree once you have started.
// You will pick exactly one fruit from every tree until you cannot, i.e.,
// you will stop when you have to pick from a third fruit type.
// Write a function to return the maximum number of fruits in both baskets.
//
// Example 1:
//
// Input: arr=['A', 'B', 'C', 'A', 'C']
// Output: 3
// Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
// Example 2:
//
// Input: arr = ['A', 'B', 'C', 'B', 'B', 'C']
// Output: 5
// Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
// Constraints:
//
// 1 <= arr.length <=
// 0 <= arr[i] < arr.length

func maxFruit(arr []rune) int {
	windowStart, maxLength := 0, 0
	fruitFrequencyMap := make(map[rune]int)
	// try to extend the range [windowStart, windowEnd]
	for windowEnd := range arr {
		fruitFrequencyMap[arr[windowEnd]] = fruitFrequencyMap[arr[windowEnd]] + 1
		// shrink the sliding window, until we're left with '2' fruits in the frequency map
		for len(fruitFrequencyMap) > 2 {
			fruitFrequencyMap[arr[windowStart]] = fruitFrequencyMap[arr[windowStart]] - 1
			if fruitFrequencyMap[arr[windowStart]] == 0 {
				delete(fruitFrequencyMap, arr[windowStart])
			}
			windowStart++ // shrink the window
		}
		maxLength = max(maxLength, windowEnd-windowStart+1)
	}
	return maxLength
}
