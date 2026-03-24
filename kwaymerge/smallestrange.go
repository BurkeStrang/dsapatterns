package kwaymerge

// Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

import (
	"container/heap"
)

type NodeElement struct {
	ElementIndex int
	ArrayIndex   int
}

type NodeHeap []*NodeElement

func (h NodeHeap) Len() int { return len(h) }
func (h NodeHeap) Less(i, j int) bool {
	return lists[h[i].ArrayIndex][h[i].ElementIndex] < lists[h[j].ArrayIndex][h[j].ElementIndex]
}
func (h NodeHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *NodeHeap) Push(x any) {
	*h = append(*h, x.(*NodeElement))
}

func (h *NodeHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

var lists [][]int

func findSmallestRange(inputLists [][]int) [2]int {
	lists = inputLists // set global variable
	minHeap := &NodeHeap{}
	heap.Init(minHeap)

	rangeStart, rangeEnd := 0, int(^uint(0)>>1)
	currentMaxNumber := -1 << 31

	for i, list := range lists {
		if len(list) > 0 {
			heap.Push(minHeap, &NodeElement{ElementIndex: 0, ArrayIndex: i})
			if list[0] > currentMaxNumber {
				currentMaxNumber = list[0]
			}
		}
	}

	for minHeap.Len() == len(lists) {
		node := heap.Pop(minHeap).(*NodeElement)
		if rangeEnd-rangeStart > currentMaxNumber-lists[node.ArrayIndex][node.ElementIndex] {
			rangeStart = lists[node.ArrayIndex][node.ElementIndex]
			rangeEnd = currentMaxNumber
		}
		node.ElementIndex++
		if len(lists[node.ArrayIndex]) > node.ElementIndex {
			heap.Push(minHeap, &NodeElement{ElementIndex: node.ElementIndex, ArrayIndex: node.ArrayIndex})
			if lists[node.ArrayIndex][node.ElementIndex] > currentMaxNumber {
				currentMaxNumber = lists[node.ArrayIndex][node.ElementIndex]
			}
		}
	}

	return [2]int{rangeStart, rangeEnd}
}
