package kwaymerge

// Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
//
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
// Output: 4
// Explanation: The 5th smallest number among all the arrays is 4, this can be verified from
// the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7], K=3
// Output: 7
// Explanation: The 3rd smallest number among all the arrays is 7.

import (
	"container/heap"
)

type Node struct {
	ElementIndex int
	ArrayIndex   int
}

type MinNodeHeap struct {
	Nodes []Node
	Lists [][]int
}

func (h MinNodeHeap) Len() int { return len(h.Nodes) }
func (h MinNodeHeap) Less(i, j int) bool {
	return h.Lists[h.Nodes[i].ArrayIndex][h.Nodes[i].ElementIndex] < h.Lists[h.Nodes[j].ArrayIndex][h.Nodes[j].ElementIndex]
}
func (h MinNodeHeap) Swap(i, j int) { h.Nodes[i], h.Nodes[j] = h.Nodes[j], h.Nodes[i] }

func (h *MinNodeHeap) Push(x any) {
	h.Nodes = append(h.Nodes, x.(Node))
}

func (h *MinNodeHeap) Pop() any {
	old := h.Nodes
	n := len(old)
	x := old[n-1]
	h.Nodes = old[0 : n-1]
	return x
}

func findKthSmallest(lists [][]int, k int) int {
	minHeap := &MinNodeHeap{Lists: lists}
	heap.Init(minHeap)

	// put the 1st element of each array in the min heap
	for i := range lists {
		if len(lists[i]) > 0 {
			heap.Push(minHeap, Node{0, i})
		}
	}

	// take the smallest (top) element form the min heap, if the running count is equal
	// to k return the number if the array of the top element has more elements, add the
	// next element to the heap
	numberCount := 0
	result := 0
	for minHeap.Len() > 0 {
		node := heap.Pop(minHeap).(Node)
		result = lists[node.ArrayIndex][node.ElementIndex]
		if numberCount++; numberCount == k {
			break
		}
		node.ElementIndex++
		if len(lists[node.ArrayIndex]) > node.ElementIndex {
			heap.Push(minHeap, node)
		}
	}
	return result
}
