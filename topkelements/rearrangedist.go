package topkelements

import (
	"container/heap"
	"strings"
)

// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at least ‘K’ distance apart from each other.
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
// Explanation: We cannot find an arrangement of the string where any two 'a' are 3 distance apart.

func reorganizeString(str string, k int) string {
	if k <= 1 {
		return str
	}

	charFrequencyMap := make(map[rune]int)
	for _, chr := range str {
		charFrequencyMap[chr]++
	}

	var maxHeap MaxCharHeap
	for char, count := range charFrequencyMap {
		maxHeap = append(maxHeap, CharFreq{char, count})
	}

	heap.Init(&maxHeap)

	var resultBuilder strings.Builder
	var queue []CharFreq

	for len(maxHeap) > 0 {
		currentEntry := heap.Pop(&maxHeap).(CharFreq)
		resultBuilder.WriteRune(currentEntry.Letter)
		currentEntry.Frequency--
		queue = append(queue, currentEntry)

		if len(queue) == k {
			entry := queue[0]
			queue = queue[1:]
			if entry.Frequency > 0 {
				heap.Push(&maxHeap, entry)
			}
		}
	}

	resultString := resultBuilder.String()
	if len(resultString) == len(str) {
		return resultString
	}
	return ""
}
