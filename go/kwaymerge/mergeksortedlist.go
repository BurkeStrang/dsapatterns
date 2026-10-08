package kwaymerge

import "container/heap"

// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

type ListNode struct {
	Val  int
	Next *ListNode
}

type MinHeap []*ListNode

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x any) {
	*h = append(*h, x.(*ListNode))
}

func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// merge merges the given lists into one sorted list.
func merge(lists []*ListNode) *ListNode {
	minHeap := &MinHeap{}
	heap.Init(minHeap)

	// put the root of each list in the min heap
	for _, root := range lists {
		if root != nil {
			heap.Push(minHeap, root)
		}
	}

	// take the smallest (top) element form the min-heap and add it to the result;
	// if the top element has a next element add it to the heap
	var resultHead, resultTail *ListNode
	for minHeap.Len() > 0 {
		node := heap.Pop(minHeap).(*ListNode)
		if resultHead == nil {
			resultHead, resultTail = node, node
		} else {
			resultTail.Next = node
			resultTail = resultTail.Next
		}
		if node.Next != nil {
			heap.Push(minHeap, node.Next)
		}
	}

	return resultHead
}
